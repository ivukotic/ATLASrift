// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "Http.h"
#include "NetServer.h"
#include "Networking.h"

#include "Object.h"
#include "Monitoring.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ATLASRIFT_API UMonitoring : public UObject
{
	GENERATED_BODY()
	
	FHttpModule* Http;

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

public:
	UMonitoring();
	~UMonitoring();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MonitoringSettings")
		FString TargetHost;

	UFUNCTION(BlueprintCallable, Category = "Report On")
	void SendReport(FString js);
};
