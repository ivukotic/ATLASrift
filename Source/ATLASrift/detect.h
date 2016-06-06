// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "GameFramework/Actor.h"
#include "detect.generated.h"

UCLASS()
class ATLASRIFT_API Adetect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Adetect();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "HMD functions")
	uint8 HMDtype();

	UFUNCTION(BlueprintCallable, Category = "HMD functions")
	bool HMDisEnabled();

	UFUNCTION(BlueprintCallable, Category = "HMD functions")
	bool HMDhasFocus();

	UFUNCTION(BlueprintCallable, Category = "HMD functions")
	bool HMDisConnected();
};
