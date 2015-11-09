// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Track.h"
#include "Http.h"
#include "GameFramework/Actor.h"
#include "Event.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EventLog, Log, All);
/**
 * 
 */
UCLASS()
class ATLASRIFT_API AEvent : public AActor
{
	GENERATED_BODY()

		
	AEvent(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;

	FHttpModule* Http;

	UPROPERTY(EditDefaultsOnly, Category = "EventServer")
		FString TargetHost;

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    int32 RunNr;
    int32 EventNr;
    int32 eventID;
    int32 totalEvents;
	FString Description;
	TArray<FString> TrackTypes;
	TArray<FString> ClusterTypes;
	TArray<FString> JetTypes;
	FVector* EventSpawnLoc;
	FRotator* EventSpawnRotation;
	FActorSpawnParameters SpawnInfo;
public:

	UPROPERTY(BlueprintReadOnly, Category = "Event elements")
		TArray<TSubclassOf<class ATrack> > Tracks;
	UPROPERTY(BlueprintReadOnly, Category = "Event elements")
		TArray<TSubclassOf<class ACluster> > Clusters;
	UPROPERTY(BlueprintReadOnly, Category = "Event elements")
		TArray<TSubclassOf<class AJet> > Jets;

	UFUNCTION(BlueprintImplementableEvent, Category = "EventServer")
		void onEventDownloaded();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		int32 GetEventNr();
	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		int32 GetRunNr();
	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		FString GetDescription();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void GetEvent();

};
