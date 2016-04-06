// Fill out your copyright notice in the Description page of Project Settings.
#include "OnlineSubSystemHeader.h"
#include "AdvancedFriendsLibrary.h"


// This is taken directly from UE4 - OnlineSubsystemSteamPrivatePCH.h as a fix for the array_count macro

// @todo Steam: Steam headers trigger secure-C-runtime warnings in Visual C++. Rather than mess with _CRT_SECURE_NO_WARNINGS, we'll just
//	disable the warnings locally. Remove when this is fixed in the SDK
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif

#pragma push_macro("ARRAY_COUNT")
#undef ARRAY_COUNT

#include <steam/steam_api.h>

#pragma pop_macro("ARRAY_COUNT")

// @todo Steam: See above
#ifdef _MSC_VER
#pragma warning(pop)
#endif

//General Log
DEFINE_LOG_CATEGORY(AdvancedFriendsLog);


int32 UAdvancedFriendsLibrary::GetFriendSteamLevel(APlayerController *PlayerController, const FBPUniqueNetId UniqueNetId)
{

	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad Player Controller!"));
		return 0;
	}

	if (!UniqueNetId.IsValid() || !UniqueNetId.UniqueNetId->IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad UniqueNetId!"));
		return 0;
	}

	if (SteamAPI_Init())
	{
		uint64 id = *((uint64*)UniqueNetId.UniqueNetId->GetBytes());

		return SteamFriends()->GetFriendSteamLevel(id);
	}

	return 0;


}

bool UAdvancedFriendsLibrary::RequestSteamFriendInfo(APlayerController *PlayerController, const FBPUniqueNetId UniqueNetId)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad Player Controller!"));
		return nullptr;
	}

	if (!UniqueNetId.IsValid() || !UniqueNetId.UniqueNetId->IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad UniqueNetId!"));
		return nullptr;
	}

	if (SteamAPI_Init())
	{
		uint64 id = *((uint64*)UniqueNetId.UniqueNetId->GetBytes());

		return !SteamFriends()->RequestUserInformation(id, false);
	}

	return false;
}

UTexture2D * UAdvancedFriendsLibrary::GetSteamFriendAvatar(APlayerController *PlayerController, const FBPUniqueNetId UniqueNetId, SteamAvatarSize AvatarSize)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad Player Controller!"));
		return nullptr;
	}

	if (!UniqueNetId.IsValid() || !UniqueNetId.UniqueNetId->IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad UniqueNetId!"));
		return nullptr;
	}

	uint32 Width = 0;
	uint32 Height = 0;

	if (SteamAPI_Init())
	{
		//Getting the PictureID from the SteamAPI and getting the Size with the ID
		//virtual bool RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly ) = 0;

		
		uint64 id = *((uint64*)UniqueNetId.UniqueNetId->GetBytes());
		int Picture = 0;
		
		switch(AvatarSize)
		{
		case SteamAvatarSize::SteamAvatar_Small: Picture = SteamFriends()->GetSmallFriendAvatar(id); break;
		case SteamAvatarSize::SteamAvatar_Medium: Picture = SteamFriends()->GetMediumFriendAvatar(id); break;
		case SteamAvatarSize::SteamAvatar_Large: Picture = SteamFriends()->GetLargeFriendAvatar(id); break;
		default: break;
		}

		if (Picture == -1)
			return NULL;

		SteamUtils()->GetImageSize(Picture, &Width, &Height);

		// STOLEN FROM ANSWERHUB :p

		if (Width > 0 && Height > 0)
		{
			//Creating the buffer "oAvatarRGBA" and then filling it with the RGBA Stream from the Steam Avatar
			uint8 *oAvatarRGBA = new uint8[Width * Height * 4];


			//Filling the buffer with the RGBA Stream from the Steam Avatar and creating a UTextur2D to parse the RGBA Steam in
			SteamUtils()->GetImageRGBA(Picture, (uint8*)oAvatarRGBA, 4 * Height * Width * sizeof(char));


			// Removed as I changed the image bit code to be RGB
			/*
			//Swap R and B channels because for some reason the games whack
			for (uint32 i = 0; i < (Width * Height * 4); i += 4)
			{
				uint8 Temp = oAvatarRGBA[i + 0];
				oAvatarRGBA[i + 0] = oAvatarRGBA[i + 2];
				oAvatarRGBA[i + 2] = Temp;
			}*/

			UTexture2D* Avatar = UTexture2D::CreateTransient(Width, Height, PF_R8G8B8A8);

			uint8* MipData = (uint8*)Avatar->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(MipData, (void*)oAvatarRGBA, Height * Width * 4);
			Avatar->PlatformData->Mips[0].BulkData.Unlock();

			// Original implementation was missing this!!
			// the hell man......
			delete[] oAvatarRGBA;

			//Setting some Parameters for the Texture and finally returning it
			Avatar->PlatformData->NumSlices = 1;
			Avatar->NeverStream = true;
			//Avatar->CompressionSettings = TC_EditorIcon;

			Avatar->UpdateResource();

			return Avatar;
		}
		else
		{
			UE_LOG(AdvancedFriendsLog, Warning, TEXT("Bad Height / Width with steam avatar!"));
		}

		return nullptr;
	}

	UE_LOG(AdvancedFriendsLog, Warning, TEXT("STEAM Couldn't be verified as initialized"));
	return nullptr;
}

void UAdvancedFriendsLibrary::SendSessionInviteToFriends(APlayerController *PlayerController, const TArray<FBPUniqueNetId> &Friends, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend Had a bad Player Controller!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	if (Friends.Num() < 1)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend Had no friends in invitation array!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	IOnlineSessionPtr SessionInterface = Online::GetSessionInterface();

	if (!SessionInterface.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend Failed to get session interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend failed to get LocalPlayer!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	TArray<TSharedRef<const FUniqueNetId>> List;
	for (int i = 0; i < Friends.Num(); i++)
	{
		TSharedRef<const FUniqueNetId> val(Friends[i].UniqueNetId.ToSharedRef());
		//TSharedRef<const FUniqueNetId> val(Friends[i].GetUniqueNetId());
		List.Add(val);
	}

	if (SessionInterface->SendSessionInviteToFriends(Player->GetControllerId(), GameSessionName, List))
	{
		Result = EBlueprintResultSwitch::Type::OnSuccess;
		return;
	}

	Result = EBlueprintResultSwitch::Type::OnFailure;
	return;
}

void UAdvancedFriendsLibrary::SendSessionInviteToFriend(APlayerController *PlayerController, const FBPUniqueNetId &FriendUniqueNetId, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend Had a bad Player Controller!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	if (!FriendUniqueNetId.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend Had a bad UniqueNetId!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	IOnlineSessionPtr SessionInterface = Online::GetSessionInterface();

	if (!SessionInterface.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend Failed to get session interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("SendSessionInviteToFriend failed to get LocalPlayer!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	if (SessionInterface->SendSessionInviteToFriend(Player->GetControllerId(), GameSessionName, *FriendUniqueNetId.GetUniqueNetId()))
	{
		Result = EBlueprintResultSwitch::Type::OnSuccess;
		return;
	}

	Result = EBlueprintResultSwitch::Type::OnFailure;
	return;
}

void UAdvancedFriendsLibrary::GetFriend(APlayerController *PlayerController, const FBPUniqueNetId FriendUniqueNetId, FBPFriendInfo &Friend)
{

	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriend Had a bad Player Controller!"));
		return;
	}

	if (!FriendUniqueNetId.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriend Had a bad UniqueNetId!"));
		return;
	}

	IOnlineFriendsPtr FriendsInterface = Online::GetFriendsInterface();

	if (!FriendsInterface.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriend Failed to get friends interface!"));
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriend failed to get LocalPlayer!"));
		return;
	}

	TSharedPtr<FOnlineFriend> fr = FriendsInterface->GetFriend(Player->GetControllerId(), *FriendUniqueNetId.GetUniqueNetId(), EFriendsLists::ToString(EFriendsLists::Type::Default));
	if (fr.IsValid())
	{
		Friend.DisplayName = fr->GetDisplayName();
		Friend.OnlineState = ((EBPOnlinePresenceState::Type)((int32)fr->GetPresence().Status.State));
		Friend.RealName = fr->GetRealName();
		Friend.UniqueNetId.SetUniqueNetId(fr->GetUserId());
		Friend.bIsPlayingSameGame = fr->GetPresence().bIsPlayingThisGame;
	}
}

void UAdvancedFriendsLibrary::IsAFriend(APlayerController *PlayerController, const FBPUniqueNetId UniqueNetId, bool &IsFriend)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad Player Controller!"));
		return;
	}

	if (!UniqueNetId.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Had a bad UniqueNetId!"));
		return;
	}

	IOnlineFriendsPtr FriendsInterface = Online::GetFriendsInterface();

	if (!FriendsInterface.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Failed to get friends interface!"));
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("IsAFriend Failed to get LocalPlayer!"));
		return;
	}

	IsFriend = FriendsInterface->IsFriend(Player->GetControllerId(), *UniqueNetId.GetUniqueNetId(), EFriendsLists::ToString(EFriendsLists::Type::Default));
}

void UAdvancedFriendsLibrary::GetStoredRecentPlayersList(FBPUniqueNetId UniqueNetId, TArray<FBPOnlineRecentPlayer> &PlayersList)
{
	IOnlineFriendsPtr FriendsInterface = Online::GetFriendsInterface();

	if (!FriendsInterface.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetRecentPlayersList Failed to get friends interface!"));
		return;
	}

	if (!UniqueNetId.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetRecentPlayersList Failed was given an invalid UniqueNetId!"));
		return;
	}

	TArray< TSharedRef<FOnlineRecentPlayer> > PlayerList;
	
	// For now getting all namespaces
	FriendsInterface->GetRecentPlayers(*(UniqueNetId.GetUniqueNetId()),"", PlayerList);

	for (int32 i = 0; i < PlayerList.Num(); i++)
	{
		TSharedRef<FOnlineRecentPlayer> Player = PlayerList[i];
		FBPOnlineRecentPlayer BPF;
		BPF.DisplayName = Player->GetDisplayName();
		BPF.RealName = Player->GetRealName();
		BPF.UniqueNetId.SetUniqueNetId(Player->GetUserId());
		PlayersList.Add(BPF);
	}
}

void UAdvancedFriendsLibrary::GetStoredFriendsList(APlayerController *PlayerController, TArray<FBPFriendInfo> &FriendsList)
{

	if (!PlayerController)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriendsList Had a bad Player Controller!"));
		return;
	}

	IOnlineFriendsPtr FriendsInterface = Online::GetFriendsInterface();
	
	if (!FriendsInterface.IsValid())
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriendsList Failed to get friends interface!"));
		return;
	}

	ULocalPlayer* Player = Cast<ULocalPlayer>(PlayerController->Player);

	if (!Player)
	{
		UE_LOG(AdvancedFriendsLog, Warning, TEXT("GetFriendsList Failed to get LocalPlayer!"));
		return;
	}


	TArray< TSharedRef<FOnlineFriend> > FriendList;
	FriendsInterface->GetFriendsList(Player->GetControllerId(), EFriendsLists::ToString((EFriendsLists::Type::Default)), FriendList);

	for (int32 i = 0; i < FriendList.Num(); i++)
	{
		TSharedRef<FOnlineFriend> Friend = FriendList[i];
		FBPFriendInfo BPF;

		BPF.OnlineState = ((EBPOnlinePresenceState::Type)((int32)Friend->GetPresence().Status.State));
		BPF.DisplayName = Friend->GetDisplayName();
		BPF.RealName = Friend->GetRealName();
		BPF.UniqueNetId.SetUniqueNetId(Friend->GetUserId());
		BPF.bIsPlayingSameGame = Friend->GetPresence().bIsPlayingThisGame;

		BPF.PresenceInfo.bIsOnline = Friend->GetPresence().bIsOnline;
		BPF.PresenceInfo.bIsPlaying = Friend->GetPresence().bIsPlaying;
		BPF.PresenceInfo.PresenceState = ((EBPOnlinePresenceState::Type)((int32)Friend->GetPresence().Status.State));
		BPF.PresenceInfo.StatusString = Friend->GetPresence().Status.StatusStr;
		BPF.PresenceInfo.bIsJoinable = Friend->GetPresence().bIsJoinable;
		BPF.PresenceInfo.bIsPlayingThisGame = Friend->GetPresence().bIsPlayingThisGame;

		FriendsList.Add(BPF);
	}
}