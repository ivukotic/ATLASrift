// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Reporter.h"

#include "NetServer.h"


// Sets default values for this component's properties
UReporter::UReporter()
{
	TargetHost = "http://atlasrift.appspot.com";
	Http = &FHttpModule::Get();
}

void UReporter::StartWork(FString parameters)
{
	UE_LOG(LogTemp, Display, TEXT("Sending START message"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	UE_LOG(LogTemp, Display, TEXT("configuration: %s"), *parameters);

	Request->SetVerb("POST");
	Request->SetURL(TargetHost + "/ATLASriftMonitor");
	Request->SetHeader("User-Agent", "ATLASriftClient/0.7");
	Request->SetHeader("Accept", "application/json");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(parameters);
	Request->OnProcessRequestComplete().BindUObject(this, &UReporter::OnResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on Sending START message"));
	}
	
}

void UReporter::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful){
	if (!Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Error in sending data."));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		UE_LOG(LogTemp, Display, TEXT("Message sent"));
	}
}

void UReporter::StopWork()
{
	UE_LOG(LogTemp, Display, TEXT("Sending STOP message"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	Request->SetVerb("GET");
	Request->SetURL(TargetHost + "/eventserver");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Accept", "application/json");
	Request->SetContentAsString("stopped");
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on Sending STOP message"));
	}
}

void  UReporter::LoadNetServers()
{
	ANetServers.Empty();
	UE_LOG(LogTemp, Display, TEXT("Loading NetServers"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
	Request->SetVerb("GET");
	Request->SetURL(TargetHost + "/netservers");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Accept", "application/json");
	Request->OnProcessRequestComplete().BindUObject(this, &UReporter::OnServersResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on receiving NetServers"));
	}
}

void UReporter::OnServersResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	UE_LOG(LogTemp, Display, TEXT("got something for netservers"));
	FString MessageBody = "";

	if (!Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Error receiving NetServers"));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		MessageBody = Response->GetContentAsString();

		UE_LOG(LogTemp, Display, TEXT("MessageBody: %s"), *MessageBody);

		TSharedPtr<FJsonObject> jServers;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(MessageBody);
		if (FJsonSerializer::Deserialize(JsonReader, jServers))
		{
			for (auto currJsonValue = jServers->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
			{

				FNetServer ns;// = new UNetServer();
				ns.hostname = (*currJsonValue).Key;
				TSharedPtr<FJsonValue> jServerDetails = (*currJsonValue).Value;
				TSharedPtr<FJsonObject> jSD = jServerDetails->AsObject();
				ns.ip = jSD->GetStringField("ip");
				ns.description = jSD->GetStringField("description");
				UE_LOG(LogTemp, Display, TEXT("Hostname: %s   IP: %s     Description: %s"), *ns.hostname, *ns.ip, *ns.description);
				ANetServers.Push(ns);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
}