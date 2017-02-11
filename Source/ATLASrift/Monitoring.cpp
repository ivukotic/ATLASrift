// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Monitoring.h"

UMonitoring::UMonitoring()
{
	Http = &FHttpModule::Get();
}

UMonitoring::~UMonitoring()
{
}


void UMonitoring::SendReport(FString parameters)
{
	UE_LOG(LogTemp, Display, TEXT("Sending Monitoring"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	UE_LOG(LogTemp, Display, TEXT("Data To Send: %s"), *parameters);

	Request->SetVerb("PUT");
	Request->SetURL(TargetHost);
	Request->SetHeader("User-Agent", "ATLASriftClient/0.7");
	Request->SetHeader("Accept", "application/json");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(parameters);
	Request->OnProcessRequestComplete().BindUObject(this, &UMonitoring::OnResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on Sending Monitoring message"));
	}

}

void UMonitoring::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	if (!Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Error in sending data.")); 
		UE_LOG(LogTemp, Error, TEXT("__ %s __"), *(Response->GetContentAsString()));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		UE_LOG(LogTemp, Display, TEXT("Message sent"));
	}
}