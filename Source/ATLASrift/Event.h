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

	UPROPERTY(EditDefaultsOnly, Category = "Tracks")
		TSubclassOf<class ATrack> Track;

	UPROPERTY()
		uint32 RunNr;
	UPROPERTY()
		uint32 EventNr;

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void SpawnTracks();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void GetEvent();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void ToggleMuons();

	
};
