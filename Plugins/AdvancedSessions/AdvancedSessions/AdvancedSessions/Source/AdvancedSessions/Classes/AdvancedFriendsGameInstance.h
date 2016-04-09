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
#include "AdvancedFriendsInterface.h"

#include "AdvancedFriendsGameInstance.generated.h"


//General Advanced Sessions Log
DECLARE_LOG_CATEGORY_EXTERN(AdvancedFriendsInterfaceLog, Log, All);

UCLASS()
class ADVANCEDSESSIONS_API UAdvancedFriendsGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UAdvancedFriendsGameInstance(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedFriendsInterface)
	bool bCallFriendInterfaceEventsOnPlayerControllers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedFriendsInterface)
	bool bCallVoiceInterfaceEventsOnPlayerControllers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedVoiceInterface)
	bool bEnableTalkingStatusDelegate;

	//virtual void PostLoad() override;
	virtual void Shutdown() override;
	virtual void Init() override;

	//*** Session invite received by local ***//
	FOnSessionInviteReceivedDelegate SessionInviteReceivedDelegate;
	FDelegateHandle SessionInviteReceivedDelegateHandle;

	//const FUniqueNetId& /*UserId*/, const FUniqueNetId& /*FromId*/, const FString& /*AppId*/, const FOnlineSessionSearchResult& /*InviteResult*/
	void OnSessionInviteReceivedMaster(const FUniqueNetId & PersonInvited, const FUniqueNetId & PersonInviting, const FString & AppId, const FOnlineSessionSearchResult& SessionToJoin);

	// After a session invite has been accepted by the local player this event is triggered, call JoinSession on the session result to join it
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedFriends")
	void OnSessionInviteReceived(int32 LocalPlayerNum, FBPUniqueNetId PersonInviting, const FString& AppId, const FBlueprintSessionResult& SessionToJoin);

	//*** Session invite accepted by local ***//
	FOnSessionUserInviteAcceptedDelegate SessionInviteAcceptedDelegate;
	FDelegateHandle SessionInviteAcceptedDelegateHandle;

	void OnSessionInviteAcceptedMaster(const bool bWasSuccessful, int32 LocalPlayer, TSharedPtr<const FUniqueNetId> PersonInviting, const FOnlineSessionSearchResult& SessionToJoin);

	// After a session invite has been accepted by the local player this event is triggered, call JoinSession on the session result to join it
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedFriends")
	void OnSessionInviteAccepted(int32 LocalPlayerNum, FBPUniqueNetId PersonInviting, const FBlueprintSessionResult& SessionToJoin);


	// After a voice status has changed this event is triggered if the bEnableTalkingStatusDelegate property is true
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedVoice")
	void OnPlayerTalkingStateChanged(FBPUniqueNetId PlayerId, bool bIsTalking);

	void OnPlayerTalkingStateChangedMaster(TSharedRef<const FUniqueNetId> PlayerId, bool bIsTalking);

	FOnPlayerTalkingStateChangedDelegate PlayerTalkingStateChangedDelegate;
	FDelegateHandle PlayerTalkingStateChangedDelegateHandle;

	//*** Session Invite Received From Friend ***//
	// REMOVED BECAUSE IT NEVER GETS CALLED
	/*FOnSessionInviteReceivedDelegate SessionInviteReceivedDelegate;
	FDelegateHandle SessionInviteReceivedDelegateHandle;

	void OnSessionInviteReceivedMaster(const FUniqueNetId &InvitedPlayer, const FUniqueNetId &FriendInviting, const FOnlineSessionSearchResult& Session);

	// After a session invite has been sent from a friend this event is triggered, call JoinSession on the session result to join it
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedFriends")
	void OnSessionInviteReceived(const FBPUniqueNetId &InvitedPlayer, const FBPUniqueNetId &FriendInviting, const FBlueprintSessionResult &Session);
	*/

	//*** Friend Invite Accepted ***//
	/*FOnInviteAcceptedDelegate FriendInviteAcceptedDelegate;
	FDelegateHandle FriendInviteAcceptedDelegateHandle;

	void OnFriendInviteAcceptedDelegateMaster(const FUniqueNetId& LocalPlayer, const FUniqueNetId &PlayerInvited);

	// After a session invite has been accepted by a friend this event is triggered
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedFriends")
	void OnFriendInviteAccepted(const FBPUniqueNetId &InvitedPlayer, const FBPUniqueNetId &PlayerInvited);
	*/

	//*** Friend Invite Rejected ***//
	/*FOnInviteRejectedDelegate SessionInviteRejectedByFriendDelegate;
	FDelegateHandle InviteRejectedByFriendDelegateHandle;

	void OnFriendInviteRejectedDelegateMaster(const FUniqueNetId& LocalPlayer, const FUniqueNetId &PlayerDeclined);

	// After a friend invite has been rejected this event is triggered
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedFriends")
	void OnFriendInviteRejected(const FBPUniqueNetId &InvitedPlayer, const FBPUniqueNetId &PlayerDeclined);
	*/

	//*** Removed By Friend ***//
	/*FOnFriendRemovedDelegate RemovedByFriendDelegate;
	FDelegateHandle RemovedByFriendDelegateHandle;

	void OnRemovedByFriendDelegateMaster(const FUniqueNetId& LocalPlayer, const FUniqueNetId &FriendRemoved);

	// After a friend removed the player this event is triggered
	UFUNCTION(BlueprintImplementableEvent, Category = "AdvancedFriends")
	void OnRemovedByFriend(const FBPUniqueNetId &InvitedPlayer, const FBPUniqueNetId &FriendRemoved);*/
};

