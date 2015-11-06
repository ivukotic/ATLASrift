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
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		int32 type;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		int32 dof;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		float chi2;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		float d0;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		float z0;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		float phi;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		float theta;
	UPROPERTY(BlueprintReadOnly, Category = "Track Parameters")
		float qop;
	UPROPERTY()
		TArray<FVector> points;

	void SetParameters(float d0, float z0, float phi, float theta, float qop);
	
};
