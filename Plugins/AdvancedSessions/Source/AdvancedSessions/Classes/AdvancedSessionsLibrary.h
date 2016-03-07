// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "OnlineSubSystemHeader.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineFriendsInterface.h"
#include "OnlineUserInterface.h"
#include "OnlineMessageInterface.h"
#include "OnlinePresenceInterface.h"
#include "Engine/GameInstance.h"
#include "OnlineSessionInterface.h"

#include "UObjectIterator.h"

#include "AdvancedSessionsLibrary.generated.h"


//General Advanced Sessions Log
DECLARE_LOG_CATEGORY_EXTERN(AdvancedSessionsLog, Log, All);


UCLASS()
class UAdvancedSessionsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		//********* Session Search Functions *************//	

		// Adds or modifies session settings in an existing array depending on if they exist already or not
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo")
		static void AddOrModifyExtraSettings(UPARAM(ref)  TArray<FSessionPropertyKeyPair> & SettingsArray, UPARAM(ref)  TArray<FSessionPropertyKeyPair> & NewOrChangedSettings, TArray<FSessionPropertyKeyPair> & ModifiedSettingsArray);

		// Get an array of the session settings from a session search result
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo")
		static void GetExtraSettings(FBlueprintSessionResult SessionResult, TArray<FSessionPropertyKeyPair> & ExtraSettings);

		// Get the current session state
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo")
		static void GetSessionState(TEnumAsByte<EBPOnlineSessionState::Type> &SessionState);

		// Get the current session settings
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo", meta = (ExpandEnumAsExecs = "Result"))
		static void GetSessionSettings(int32 &NumConnections, int32 &NumPrivateConnections, bool &bIsLAN, bool &bIsDedicated, bool &bIsAnticheatEnabled, int32 &BuildUniqueID, TArray<FSessionPropertyKeyPair> &ExtraSettings, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

		// Check if someone is in the current session
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo")
		static void IsPlayerInSession(const FBPUniqueNetId &PlayerToCheck, bool &bIsInSession);
		
		// Make a literal session search parameter
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo|Literals")
		static FSessionsSearchSetting MakeLiteralSessionSearchProperty(FSessionPropertyKeyPair SessionSearchProperty, EOnlineComparisonOpRedux::Type ComparisonOp);


		//********* Session Information Functions ***********//

		// Get the Unique Current Build ID
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo")
		static void GetCurrentUniqueBuildID(int32 &UniqueBuildId);
		
		// Get the Unique Build ID from a session search result
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo")
		static void GetUniqueBuildID(FBlueprintSessionResult SessionResult, int32 &UniqueBuildId);

		// Get session custom information key/value as Byte (For Enums)
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo", meta = (ExpandEnumAsExecs = "SearchResult"))
		static void GetSessionPropertyByte(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, uint8 &SettingValue);

		// Get session custom information key/value as Bool
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo", meta = (ExpandEnumAsExecs = "SearchResult"))
		static void GetSessionPropertyBool(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, bool &SettingValue);

		// Get session custom information key/value as String
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo", meta = (ExpandEnumAsExecs = "SearchResult"))
		static void GetSessionPropertyString(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, FString &SettingValue);

		// Get session custom information key/value as Int
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo", meta = (ExpandEnumAsExecs = "SearchResult"))
		static void GetSessionPropertyInt(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, int32 &SettingValue);

		// Get session custom information key/value as Float
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|SessionInfo", meta = (ExpandEnumAsExecs = "SearchResult"))
		static void GetSessionPropertyFloat(const TArray<FSessionPropertyKeyPair> & ExtraSettings, FName SettingName, TEnumAsByte<ESessionSettingSearchResult::Type> &SearchResult, float &SettingValue);


		// Make a literal session custom information key/value pair from Byte (For Enums)
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo|Literals")
		static FSessionPropertyKeyPair MakeLiteralSessionPropertyByte(FName Key, uint8 Value);

		// Make a literal session custom information key/value pair from Bool
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo|Literals")
		static FSessionPropertyKeyPair MakeLiteralSessionPropertyBool(FName Key, bool Value);

		// Make a literal session custom information key/value pair from String
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo|Literals")
		static FSessionPropertyKeyPair MakeLiteralSessionPropertyString(FName Key, FString Value);

		// Make a literal session custom information key/value pair from Int
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo|Literals")
		static FSessionPropertyKeyPair MakeLiteralSessionPropertyInt(FName Key, int32 Value);

		// Make a literal session custom information key/value pair from Float
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|SessionInfo|Literals")
		static FSessionPropertyKeyPair MakeLiteralSessionPropertyFloat(FName Key, float Value);


		//******* Player ID functions *********//

		// Get the unique net id of a network player attached to the given controller
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|PlayerInfo|PlayerID")
		static void GetUniqueNetID(APlayerController *PlayerController, FBPUniqueNetId &UniqueNetId);

		// Get the unique net id of a network player who is assigned the the given player state
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|PlayerInfo|PlayerID")
		static void GetUniqueNetIDFromPlayerState(APlayerState *PlayerState, FBPUniqueNetId &UniqueNetId);

		// Check if a UniqueNetId is a friend
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|UniqueNetId")
		static void UniqueNetIdToString(const FBPUniqueNetId &UniqueNetId, FString &String);

		//******** Player Name Functions **********//

		// Get the player name of a network player attached to the given controller
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|PlayerInfo|PlayerName")
		static void GetPlayerName(APlayerController *PlayerController, FString &PlayerName);

		// Set the player name of a network player attached to the given controller
		UFUNCTION(BlueprintCallable, Category = "Online|AdvancedSessions|PlayerInfo|PlayerName")
		static void SetPlayerName(APlayerController *PlayerController, FString PlayerName);

		//********** Misc Player Info Functions *********//

		// Get the number of network players
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|PlayerInfo|Misc", meta = (bIgnoreSelf = "true", WorldContext = "WorldContextObject", DisplayName = "GetNumNetworkPlayers"))
		static void GetNumberOfNetworkPlayers(UObject* WorldContextObject, int32 &NumNetPlayers);

		// Get the network player index of the given controller
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|PlayerInfo|Misc")
		static void GetNetPlayerIndex(APlayerController *PlayerController, int32 &NetPlayerIndex);

		// Checks if the stated session subsystem is active
		UFUNCTION(BlueprintPure, Category = "Online|AdvancedSessions|Misc")
		static bool HasOnlineSubsystem(FName SubSystemName);

		
};	
