// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "Http.h"

#include "Components/ActorComponent.h"
#include "Reporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ATLASRIFT_API UReporter : public UActorComponent
{

	GENERATED_BODY()

	FHttpModule* Http;

	UPROPERTY(EditDefaultsOnly, Category = "ReporterSettings")
	FString TargetHost;

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

public:	
	// Sets default values for this component's properties
	UReporter();

	UFUNCTION(BlueprintCallable, Category = "Report On")
		void StartWork(FString js);
	UFUNCTION(BlueprintCallable, Category = "Report On")
		void StopWork();
};
