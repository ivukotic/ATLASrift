// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "Http.h"

#include "Components/ActorComponent.h"
#include "Reporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ATLASRIFT_API UReporter : public UActorComponent
{
	
	FHttpModule* Http;

	UPROPERTY(EditDefaultsOnly, Category = "EventServer")
		FString TargetHost;
	GENERATED_BODY()
	

public:	
	// Sets default values for this component's properties
	UReporter();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Report On")
		void StartWork();
	UFUNCTION(BlueprintCallable, Category = "Report On")
		void StopWork();
};
