// Fill out your copyright notice in the Description page of Project Settings.
#include "OnlineSubSystemHeader.h"
#include "AdvancedSessionsLibrary.h"

//General Log
DEFINE_LOG_CATEGORY(AdvancedSessionsLog);

void UAdvancedSessionsLibrary::GetCurrentUniqueBuildID(int32 &UniqueBuildId)
{
	UniqueBuildId = GetBuildUniqueId();
}

void UAdvancedSessionsLibrary::GetUniqueBuildID(FBlueprintSessionResult SessionResult, int32 &UniqueBuildId)
{
	UniqueBuildId = SessionResult.OnlineResult.Session.SessionSettings.BuildUniqueId;
}

void UAdvancedSessionsLibrary::AddOrModifyExtraSettings(UPARAM(ref) TArray<FSessionPropertyKeyPair> & SettingsArray, UPARAM(ref) TArray<FSessionPropertyKeyPair> & NewOrChangedSettings, TArray<FSessionPropertyKeyPair> & ModifiedSettingsArray)
{
	ModifiedSettingsArray = SettingsArray;

	bool bFoundSetting = false;
	// For each new setting
	for (const FSessionPropertyKeyPair& Setting : NewOrChangedSettings)
	{
		bFoundSetting = false;

		for (FSessionPropertyKeyPair & itr : ModifiedSettingsArray)
		{
			// Manually comparing the keys
			if (itr.Key == Setting.Key)
			{
				bFoundSetting = true;
				itr.Data = Setting.Data;
			}
		}

		// If it was not found, add to the array instead
		if (!bFoundSetting)
		{
			ModifiedSettingsArray.Add(Setting);
		}
	}

}

void UAdvancedSessionsLibrary::GetExtraSettings(FBlueprintSessionResult SessionResult, TArray<FSessionPropertyKeyPair> & ExtraSettings)
{
	FSessionPropertyKeyPair NewSetting;
	for (auto& Elem : SessionResult.OnlineResult.Session.SessionSettings.Settings)
	{
		NewSetting.Key = Elem.Key;
		NewSetting.Data = Elem.Value.Data;
		ExtraSettings.Add(NewSetting);
	}
}

void UAdvancedSessionsLibrary::GetSessionState(TEnumAsByte<EBPOnlineSessionState::Type> &SessionState)
{
	IOnlineSessionPtr SessionInterface = Online::GetSessionInterface();

	if (!SessionInterface.IsValid())
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetSessionState couldn't get the session interface!"));
		return;
	}

	SessionState = ((EBPOnlineSessionState::Type)SessionInterface->GetSessionState(GameSessionName));
}

void UAdvancedSessionsLibrary::GetSessionSettings(int32 &NumConnections, int32 &NumPrivateConnections, bool &bIsLAN, bool &bIsDedicated, bool &bIsAnticheatEnabled, int32 &BuildUniqueID, TArray<FSessionPropertyKeyPair> &ExtraSettings, TEnumAsByte<EBlueprintResultSwitch::Type> &Result)
{
	IOnlineSessionPtr SessionInterface = Online::GetSessionInterface();

	if (!SessionInterface.IsValid())
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetSessionSettings couldn't get the session interface!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	FOnlineSessionSettings* settings = SessionInterface->GetSessionSettings(GameSessionName);
	if (!settings)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetSessionSettings couldn't get the session settings!"));
		Result = EBlueprintResultSwitch::Type::OnFailure;
		return;
	}

	BuildUniqueID = settings->BuildUniqueId;
	NumConnections = settings->NumPublicConnections;
	NumPrivateConnections = settings->NumPrivateConnections;
	bIsLAN = settings->bIsLANMatch;
	bIsDedicated = settings->bIsDedicated;
	bIsAnticheatEnabled = settings->bAntiCheatProtected;
	
	FSessionPropertyKeyPair NewSetting;

	for (auto& Elem : settings->Settings)
	{
		NewSetting.Key = Elem.Key;
		NewSetting.Data = Elem.Value.Data;
		ExtraSettings.Add(NewSetting);
	}

	Result = EBlueprintResultSwitch::Type::OnSuccess;
}

void UAdvancedSessionsLibrary::IsPlayerInSession(const FBPUniqueNetId &PlayerToCheck, bool &bIsInSession)
{
	IOnlineSessionPtr SessionInterface = Online::GetSessionInterface();

	if (!SessionInterface.IsValid())
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("IsPlayerInSession couldn't get the session interface!"));
		bIsInSession = false;
		return;
	}

	bIsInSession = SessionInterface->IsPlayerInSession(GameSessionName, *PlayerToCheck.GetUniqueNetId());
}

FSessionsSearchSetting UAdvancedSessionsLibrary::MakeLiteralSessionSearchProperty(FSessionPropertyKeyPair SessionSearchProperty, EOnlineComparisonOpRedux::Type ComparisonOp)
{
	FSessionsSearchSetting setting;
	setting.PropertyKeyPair = SessionSearchProperty;
	setting.ComparisonOp = ComparisonOp;

	return setting;
}

FSessionPropertyKeyPair UAdvancedSessionsLibrary::MakeLiteralSessionPropertyByte(FName Key, uint8 Value)
{
	FSessionPropertyKeyPair Prop;
	Prop.Key = Key;
	Prop.Data.SetValue((int32)Value);
	return Prop;
}

FSessionPropertyKeyPair UAdvancedSessionsLibrary::MakeLiteralSessionPropertyBool(FName Key, bool Value)
{
	FSessionPropertyKeyPair Prop;
	Prop.Key = Key;
	Prop.Data.SetValue(Value);
	return Prop;
}

FSessionPropertyKeyPair UAdvancedSessionsLibrary::MakeLiteralSessionPropertyString(FName Key, FString Value)
{
	FSessionPropertyKeyPair Prop;
	Prop.Key = Key;
	Prop.Data.SetValue(Value);
	return Prop;
}

FSessionPropertyKeyPair UAdvancedSessionsLibrary::MakeLiteralSessionPropertyInt(FName Key, int32 Value)
{
	FSessionPropertyKeyPair Prop;
	Prop.Key = Key;
	Prop.Data.SetValue(Value);
	return Prop;
}

FSessionPropertyKeyPair UAdvancedSessionsLibrary::MakeLiteralSessionPropertyFloat(FName Key, float Value)
{
	FSessionPropertyKeyPair Prop;
	Prop.Key = Key;
	Prop.Data.SetValue(Value);
	return Prop;
}

void UAdvancedSessionsLibrary::GetSessionPropertyByte(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, uint8 &SettingValue)
{
	for (FSessionPropertyKeyPair itr : ExtraSettings)
	{
		if (itr.Key == SettingName)
		{
			if (itr.Data.GetType() == EOnlineKeyValuePairDataType::Int32)
			{
				int32 Val;
				itr.Data.GetValue(Val);
				SettingValue = (uint8)(Val);
				SearchResult = ESessionSettingSearchResult::Type::Found;
			}
			else
			{
				SearchResult = ESessionSettingSearchResult::Type::WrongType;
			}
			return;
		}
	}

	SearchResult = ESessionSettingSearchResult::Type::NotFound;
	return;
}

void UAdvancedSessionsLibrary::GetSessionPropertyBool(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, bool &SettingValue)
{
	for (FSessionPropertyKeyPair itr : ExtraSettings)
	{
		if (itr.Key == SettingName)
		{
			if (itr.Data.GetType() == EOnlineKeyValuePairDataType::Bool)
			{
				itr.Data.GetValue(SettingValue);
				SearchResult = ESessionSettingSearchResult::Type::Found;
			}
			else
			{
				SearchResult = ESessionSettingSearchResult::Type::WrongType;
			}
			return;
		}
	}

	SearchResult = ESessionSettingSearchResult::Type::NotFound;
	return;
}

void UAdvancedSessionsLibrary::GetSessionPropertyString(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, FString &SettingValue)
{
	for (FSessionPropertyKeyPair itr : ExtraSettings)
	{
		if (itr.Key == SettingName)
		{
			if (itr.Data.GetType() == EOnlineKeyValuePairDataType::String)
			{
				itr.Data.GetValue(SettingValue);
				SearchResult = ESessionSettingSearchResult::Type::Found;
			}
			else
			{
				SearchResult = ESessionSettingSearchResult::Type::WrongType;
			}
			return;
		}
	}

	SearchResult = ESessionSettingSearchResult::Type::NotFound;
	return;
}

void UAdvancedSessionsLibrary::GetSessionPropertyInt(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, int32 &SettingValue)
{
	for (FSessionPropertyKeyPair itr : ExtraSettings)
	{
		if (itr.Key == SettingName)
		{
			if (itr.Data.GetType() == EOnlineKeyValuePairDataType::Int32)
			{
				itr.Data.GetValue(SettingValue);
				SearchResult = ESessionSettingSearchResult::Type::Found;
			}
			else
			{
				SearchResult = ESessionSettingSearchResult::Type::WrongType;
			}
			return;
		}
	}

	SearchResult = ESessionSettingSearchResult::Type::NotFound;
	return;
}

void UAdvancedSessionsLibrary::GetSessionPropertyFloat(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, float &SettingValue)
{
	for (FSessionPropertyKeyPair itr : ExtraSettings)
	{
		if (itr.Key == SettingName)
		{
			if (itr.Data.GetType() == EOnlineKeyValuePairDataType::Float)
			{
				itr.Data.GetValue(SettingValue);
				SearchResult = ESessionSettingSearchResult::Type::Found;
			}
			else
			{
				SearchResult = ESessionSettingSearchResult::Type::WrongType;
			}
			return;
		}
	}

	SearchResult = ESessionSettingSearchResult::Type::NotFound;
	return;
}


bool UAdvancedSessionsLibrary::HasOnlineSubsystem(FName SubSystemName)
{
	return((IOnlineSubsystem::Get(SubSystemName) != NULL));
}

void UAdvancedSessionsLibrary::GetNetPlayerIndex(APlayerController *PlayerController, int32 &NetPlayerIndex)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetNetPlayerIndex received a bad PlayerController!"));
		NetPlayerIndex = 0;
		return;
	}

	NetPlayerIndex = PlayerController->NetPlayerIndex;
	return;
}

void UAdvancedSessionsLibrary::UniqueNetIdToString(const FBPUniqueNetId& UniqueNetId, FString &String)
{
	const FUniqueNetId * ID = UniqueNetId.GetUniqueNetId();

	if ( !ID )
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("UniqueNetIdToString received a bad UniqueNetId!"));
		String = "ERROR, BAD UNIQUE NET ID";
	}
	else
		String = ID->ToString();
}


void UAdvancedSessionsLibrary::GetUniqueNetID(APlayerController *PlayerController, FBPUniqueNetId &UniqueNetId)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetUniqueNetIdFromController received a bad PlayerController!"));
		return;
	}

	if (APlayerState* PlayerState = (PlayerController != NULL) ? PlayerController->PlayerState : NULL)
	{
		UniqueNetId.SetUniqueNetId(PlayerState->UniqueId.GetUniqueNetId());
		if (!UniqueNetId.IsValid())
		{
			UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetUniqueNetIdFromController couldn't get the player uniquenetid!"));
		}
		return;
	}
}

void UAdvancedSessionsLibrary::GetUniqueNetIDFromPlayerState(APlayerState *PlayerState, FBPUniqueNetId &UniqueNetId)
{
	if (!PlayerState)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetUniqueNetIdFromPlayerState received a bad PlayerState!"));
		return;
	}

	UniqueNetId.SetUniqueNetId(PlayerState->UniqueId.GetUniqueNetId());
	if (!UniqueNetId.IsValid())
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetUniqueNetIdFromPlayerState couldn't get the player uniquenetid!"));
	}
	return;
}

void UAdvancedSessionsLibrary::SetPlayerName(APlayerController *PlayerController, FString PlayerName)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("SetLocalPlayerNameFromController Bad Player Controller!"));
		return;
	}

	if (APlayerState* PlayerState = (PlayerController != NULL) ? PlayerController->PlayerState : NULL)
	{
		PlayerState->SetPlayerName(PlayerName);
		return;
	}
	else
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("SetLocalPlayerNameFromController had a bad player state!"));
	}
}

void UAdvancedSessionsLibrary::GetPlayerName(APlayerController *PlayerController, FString &PlayerName)
{
	if (!PlayerController)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetLocalPlayerNameFromController Bad Player Controller!"));
		return;
	}

	if (APlayerState* PlayerState = (PlayerController != NULL) ? PlayerController->PlayerState : NULL)
	{
		PlayerName = PlayerState->PlayerName;
		return;
	}
	else
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetLocalPlayerNameFromController had a bad player state!"));
	}
}

void UAdvancedSessionsLibrary::GetNumberOfNetworkPlayers(UObject* WorldContextObject, int32 &NumNetPlayers)
{
	//Get an actor to GetWorld() from
	/*TObjectIterator<AActor> Itr;
	if (!Itr)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetNumberOfNetworkPlayers Failed to get iterator!"));
		return;
	}*/
	//~~~~~~~~~~~~

	//Get World
	UWorld* TheWorld = GEngine->GetWorldFromContextObject(WorldContextObject);

	if (!TheWorld)
	{
		UE_LOG(AdvancedSessionsLog, Warning, TEXT("GetNumberOfNetworkPlayers Failed to get World()!"));
		return;
	}
	TArray<class APlayerState*>& PlayerArray = (TheWorld->GetGameState()->PlayerArray);
	NumNetPlayers = PlayerArray.Num();
}
