// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Track.h"
#include "Http.h"
#include "GameFramework/Actor.h"
#include "Event.generated.h"

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

public:

	UPROPERTY(EditDefaultsOnly, Category = "Event Visualizations")
		TArray<TSubclassOf<class ATrack> > IDSegments;
	UPROPERTY(EditDefaultsOnly, Category = "Event Visualizations")
		TArray<TSubclassOf<class ATrack> > MuonSegments;
	UPROPERTY(EditDefaultsOnly, Category = "Event Visualizations")
		TArray<TSubclassOf<class ATrack> > Clusters;
	UPROPERTY(EditDefaultsOnly, Category = "Event Visualizations")
		TArray<TSubclassOf<class ATrack> > Jets;

	UPROPERTY()
		int32 RunNr;
	UPROPERTY()
		int32 EventNr;

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		int32 GetEventNr();
	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		int32 GetRunNr();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void SpawnTracks();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void GetEvent();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void ToggleMuons();

	
};
