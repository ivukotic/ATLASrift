// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Track.generated.h"

/**
 * 
 */
UCLASS()
class ATLASRIFT_API ATrack : public AActor
{
	GENERATED_BODY()
	
		ATrack(const FObjectInitializer& ObjectInitializer);
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Track Parameters")
		float px;
	UPROPERTY(EditDefaultsOnly, Category = "Track Parameters")
		float py;
	UPROPERTY(EditDefaultsOnly, Category = "Track Parameters")
		float pz;
	UPROPERTY(EditDefaultsOnly, Category = "Track Parameters")
		bool charge;
	UPROPERTY()
		float x1;
	UPROPERTY()
		float y1;

	void SetParameters(float px, float py, float pz, bool charge);
	
};
