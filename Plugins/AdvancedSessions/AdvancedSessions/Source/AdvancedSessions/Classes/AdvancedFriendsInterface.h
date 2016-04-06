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
#include "OnlineSessionSettings.h"
#include "UObjectIterator.h"
#include "BlueprintDataDefinitions.h"
#include "AdvancedFriendsInterface.generated.h"


UINTERFACE(MinimalAPI)
class UAdvancedFriendsInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IAdvancedFriendsInterface
{
	GENERATED_IINTERFACE_BODY()
public:
	
	// Called when the designated LocalUser has accepted a session invite, use JoinSession on result to connect
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnSessionInviteAccepted"))
	void OnSessionInviteReceived(FBPUniqueNetId PersonInviting, const FBlueprintSessionResult& SearchResult);

	// Called when the designated LocalUser has accepted a session invite, use JoinSession on result to connect
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnSessionInviteAccepted"))
	void OnSessionInviteAccepted(FBPUniqueNetId PersonInviting, const FBlueprintSessionResult& SearchResult);

	// Called when the designated LocalUser has accepted a session invite, use JoinSession on result to connect
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnPlayerVoiceStateChanged"))
	void OnPlayerVoiceStateChanged(FBPUniqueNetId PlayerId, bool bIsTalking);

	// REMOVED BECAUSE IT WAS NEVER BEING CALLED
	// Called when the designated LocalUser has received a session invite, use JoinSession on result to connect
	//UFUNCTION(BlueprintImplementableEvent, meta = (FriendlyName = "OnSessionInviteReceived"))
	//void OnSessionInviteReceived(const FBPUniqueNetId &FriendInviting, const FBlueprintSessionResult &Session);

};	
