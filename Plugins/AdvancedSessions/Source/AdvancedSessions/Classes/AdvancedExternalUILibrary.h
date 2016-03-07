// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "OnlineSubSystemHeader.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Online.h"
#include "OnlineSubsystem.h"
#include "BlueprintDataDefinitions.h"
//#include "OnlineFriendsInterface.h"
//#include "OnlineUserInterface.h"
//#include "OnlineMessageInterface.h"
//#include "OnlinePresenceInterface.h"
//#include "Engine/GameInstance.h"
#include "OnlineSessionInterface.h"

//#include "UObjectIterator.h"

#include "AdvancedExternalUILibrary.generated.h"


//General Advanced Sessions Log
DECLARE_LOG_CATEGORY_EXTERN(AdvancedExternalUILog, Log, All);

UCLASS()
class UAdvancedExternalUILibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	//********* External UI Functions *************//

	// Show the UI that handles the Friends list
	UFUNCTION(BlueprintCallable, Category = "Online|AdvancedExternalUI", meta = (ExpandEnumAsExecs = "Result"))
	static void ShowFriendsUI(APlayerController *PlayerController, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

	// Show the UI that handles inviting people to your game
	UFUNCTION(BlueprintCallable, Category = "Online|AdvancedExternalUI", meta = (ExpandEnumAsExecs = "Result"))
	static void ShowInviteUI(APlayerController *PlayerController, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

	// Show the UI that shows the leaderboard (doesn't work with steam)
	UFUNCTION(BlueprintCallable, Category = "Online|AdvancedExternalUI", meta = (ExpandEnumAsExecs = "Result"))
	static void ShowLeaderBoardUI(FString LeaderboardName, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

	// Show the UI that shows a web URL
	UFUNCTION(BlueprintCallable, Category = "Online|AdvancedExternalUI", meta = (ExpandEnumAsExecs = "Result"))
	static void ShowWebURLUI(FString URLToShow, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

	// Show the UI that shows the profile of a uniquenetid
	UFUNCTION(BlueprintCallable, Category = "Online|AdvancedExternalUI", meta = (ExpandEnumAsExecs = "Result"))
	static void ShowProfileUI(const FBPUniqueNetId PlayerViewingProfile, const FBPUniqueNetId PlayerToViewProfileOf, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

	// Show the UI that shows the account upgrade UI (doesn't work with steam)
	UFUNCTION(BlueprintCallable, Category = "Online|AdvancedExternalUI", meta = (ExpandEnumAsExecs = "Result"))
	static void ShowAccountUpgradeUI(const FBPUniqueNetId PlayerRequestingAccountUpgradeUI, TEnumAsByte<EBlueprintResultSwitch::Type> &Result);

};	
