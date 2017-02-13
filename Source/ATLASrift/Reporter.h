// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "Http.h"
#include "NetServer.h"
#include "Networking.h"

#include "Components/ActorComponent.h"
#include "Reporter.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ATLASRIFT_API UReporter : public UActorComponent
{

	GENERATED_BODY()

	FHttpModule* Http;

	UPROPERTY(EditDefaultsOnly, Category = "ReporterSettings")
	FString TargetHost;

	void OnServersResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	//FSocket* SenderSocket;
	//ISocketSubsystem* SocketSubsystem;
	//FIPv4Endpoint RemoteEndpoint;
	//FIPv4Address RemoteAddress;

public:	
	// Sets default values for this component's properties
	UReporter();

	UPROPERTY(BlueprintReadOnly, Category = "Event elements")
		TArray<FNetServer> ANetServers;
	UFUNCTION(BlueprintCallable, Category = "Server")
		void LoadNetServers();
	UFUNCTION(BlueprintCallable, Category = "Server")
		bool HostAServer(FString description);
	//UFUNCTION(BlueprintCallable, Category = "Server")
	//	void KeepAlive(int32 clients);
	//UFUNCTION(BlueprintCallable, Category = "Server")
	//	void KeepAliveUDP(FString message);

};
