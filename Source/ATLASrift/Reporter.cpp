// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Reporter.h"


// Sets default values for this component's properties
UReporter::UReporter()
{
	TargetHost = "http://waniotest.appspot.com";
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