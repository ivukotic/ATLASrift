// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Reporter.h"


// Sets default values for this component's properties
UReporter::UReporter()
{
	TargetHost = "http://waniotest.appspot.com";
	Http = &FHttpModule::Get();
}


// Called when the game starts
void UReporter::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UReporter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	// Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void UReporter::StartWork()
{

	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
	
	Request->SetVerb("GET");
	Request->SetURL(TargetHost + "/eventserver");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Accept", "application/json");
	Request->SetContentAsString("started");
	if (!Request->ProcessRequest())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("ERROR on processing request!"));
	}
}

void UReporter::StopWork()
{

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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("ERROR on processing request!"));
	}
}