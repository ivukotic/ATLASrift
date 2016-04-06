// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "OnlineSubSystemHeader.h"
#include "CreateSessionCallbackProxyAdvanced.h"

//////////////////////////////////////////////////////////////////////////
// UCreateSessionCallbackProxyAdvanced

UCreateSessionCallbackProxyAdvanced::UCreateSessionCallbackProxyAdvanced(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, CreateCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateCompleted))
	, StartCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartCompleted))
	, NumPublicConnections(1)
{
}

UCreateSessionCallbackProxyAdvanced* UCreateSessionCallbackProxyAdvanced::CreateAdvancedSession(UObject* WorldContextObject, const TArray<FSessionPropertyKeyPair> &ExtraSettings, class APlayerController* PlayerController, int32 PublicConnections, int32 PrivateConnections, bool bUseLAN, bool bAllowInvites, bool bIsDedicatedServer, bool bUsePresence, bool bAllowJoinViaPresence, bool bAllowJoinViaPresenceFriendsOnly, bool bAntiCheatProtected, bool bUsesStats, bool bShouldAdvertise)
{
	UCreateSessionCallbackProxyAdvanced* Proxy = NewObject<UCreateSessionCallbackProxyAdvanced>();
	Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->NumPublicConnections = PublicConnections;
	Proxy->NumPrivateConnections = PrivateConnections;
	Proxy->bUseLAN = bUseLAN;
	Proxy->WorldContextObject = WorldContextObject;
	Proxy->bAllowInvites = bAllowInvites;
	Proxy->ExtraSettings = ExtraSettings;
	Proxy->bDedicatedServer = bIsDedicatedServer;
	Proxy->bUsePresence = bUsePresence;
	Proxy->bAllowJoinViaPresence = bAllowJoinViaPresence;
	Proxy->bAllowJoinViaPresenceFriendsOnly = bAllowJoinViaPresenceFriendsOnly;
	Proxy->bAntiCheatProtected = bAntiCheatProtected;
	Proxy->bUsesStats = bUsesStats;
	Proxy->bShouldAdvertise = bShouldAdvertise;
	return Proxy;
}

void UCreateSessionCallbackProxyAdvanced::Activate()
{
	FOnlineSubsystemBPCallHelperAdvanced Helper(TEXT("CreateSession"), GEngine->GetWorldFromContextObject(WorldContextObject));
	
	if (PlayerControllerWeakPtr.IsValid() )
		Helper.QueryIDFromPlayerController(PlayerControllerWeakPtr.Get());

	if (Helper.OnlineSub != nullptr)
	{
		auto Sessions = Helper.OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			CreateCompleteDelegateHandle = Sessions->AddOnCreateSessionCompleteDelegate_Handle(CreateCompleteDelegate);
			
			FOnlineSessionSettings Settings;
			Settings.NumPublicConnections = NumPublicConnections;
			Settings.NumPrivateConnections = NumPrivateConnections;
			Settings.bShouldAdvertise = true;
			Settings.bAllowJoinInProgress = true;
			Settings.bIsLANMatch = bUseLAN;
			Settings.bUsesPresence = bUsePresence;
			Settings.bAllowJoinViaPresence = true;
			Settings.bIsDedicated = bDedicatedServer;
			Settings.bAllowJoinViaPresenceFriendsOnly = bAllowJoinViaPresenceFriendsOnly;
			Settings.bAntiCheatProtected = bAntiCheatProtected;
			Settings.bUsesStats = bUsesStats;
			Settings.bShouldAdvertise = bShouldAdvertise;

			// These are about the only changes over the standard Create Sessions Node
			Settings.bAllowInvites = bAllowInvites;
			
			FOnlineSessionSetting ExtraSetting;
			for (int i = 0; i < ExtraSettings.Num(); i++)
			{
				ExtraSetting.Data = ExtraSettings[i].Data;
				//		ViaOnlineServiceAndPing
				ExtraSetting.AdvertisementType = EOnlineDataAdvertisementType::ViaOnlineService;
				Settings.Settings.Add(ExtraSettings[i].Key, ExtraSetting);
			}
			

			if (PlayerControllerWeakPtr.IsValid() && Helper.UserID.IsValid())
				Sessions->CreateSession(*Helper.UserID, GameSessionName, Settings);
			else
				Sessions->CreateSession(0, GameSessionName, Settings);

			// OnCreateCompleted will get called, nothing more to do now
			return;
		}
		else
		{
			FFrame::KismetExecutionMessage(TEXT("Sessions not supported by Online Subsystem"), ELogVerbosity::Warning);
		}
	}

	// Fail immediately
	OnFailure.Broadcast();
}

void UCreateSessionCallbackProxyAdvanced::OnCreateCompleted(FName SessionName, bool bWasSuccessful)
{
	FOnlineSubsystemBPCallHelperAdvanced Helper(TEXT("CreateSessionCallback"), GEngine->GetWorldFromContextObject(WorldContextObject));
	//Helper.QueryIDFromPlayerController(PlayerControllerWeakPtr.Get());

	if (Helper.OnlineSub != nullptr)
	{
		auto Sessions = Helper.OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			Sessions->ClearOnCreateSessionCompleteDelegate_Handle(CreateCompleteDelegateHandle);
			
			if (bWasSuccessful)
			{
				StartCompleteDelegateHandle = Sessions->AddOnStartSessionCompleteDelegate_Handle(StartCompleteDelegate);
				Sessions->StartSession(GameSessionName);

				// OnStartCompleted will get called, nothing more to do now
				return;
			}
		}
	}

	if (!bWasSuccessful)
	{
		OnFailure.Broadcast();
	}
}

void UCreateSessionCallbackProxyAdvanced::OnStartCompleted(FName SessionName, bool bWasSuccessful)
{
	FOnlineSubsystemBPCallHelperAdvanced Helper(TEXT("StartSessionCallback"), GEngine->GetWorldFromContextObject(WorldContextObject));
	Helper.QueryIDFromPlayerController(PlayerControllerWeakPtr.Get());

	if (Helper.OnlineSub != nullptr)
	{
		auto Sessions = Helper.OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			Sessions->ClearOnStartSessionCompleteDelegate_Handle(StartCompleteDelegateHandle);
		}
	}

	if (bWasSuccessful)
	{
		OnSuccess.Broadcast();
	}
	else
	{
		OnFailure.Broadcast();
	}
}
