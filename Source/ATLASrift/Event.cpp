// Fill out your copyright notice in the Description page of Project Settings.


#include "ATLASrift.h"
#include "Json.h"
#include "ParticleDefinitions.h"
#include "Event.h"


AEvent::AEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TargetHost = "http://waniotest.appspot.com";
	Http = &FHttpModule::Get();

}

void AEvent::BeginPlay()
{
	Super::BeginPlay();
}




void AEvent::GetEvent()
{

	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HTTP initialized OK!"));

	Request->SetVerb("GET");
	Request->SetURL(TargetHost + "/eventserver");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	//Request->SetHeader("Content-Type", "application/json");
	Request->SetHeader("Accept", "application/json");
	Request->OnProcessRequestComplete().BindUObject(this, &AEvent::OnResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Error on getting event."));
	}
}

void AEvent::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

	FString MessageBody = "";
	// If HTTP fails client-side, this will still be called but with a NULL shared pointer!
	if (!Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Error on getting event payload."));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		MessageBody = Response->GetContentAsString();

		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(MessageBody);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			RunNr = JsonParsed->GetNumberField("run");
			EventNr = JsonParsed->GetNumberField("event"); 
			UE_LOG(LogTemp, Display, TEXT("{\"run: %d event: %d\"}"), RunNr, EventNr);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("{\"run: %d event: %d\"}"), RunNr, EventNr));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
}

void AEvent::SpawnTracks(){
	FActorSpawnParameters SpawnInfo;
	//SpawnInfo.SpawnCollisionHandlingOverride;
	SpawnInfo.Owner = this;
	SpawnInfo.bDeferConstruction = false;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Generating Tracks"));
	}

	//for (int x = 0; x < 10; x++)
	//{
		//for (int y = 0; y < 10; y++)
		//{
			FVector EventSpawnLoc(0.0f, 0.0f, 0.0f);
			FRotator EventSpawnRotation(0.0f, 0.0f, 0.0f);
			//ATrack* idSegment = AEvent::GetWorld()->SpawnActor<ATrack>(ATrack::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
			ATrack* idSegment = AEvent::GetWorld()->SpawnActor<ATrack>(IDSegments[0], EventSpawnLoc, EventSpawnRotation, SpawnInfo);
			idSegment->SetParameters(123.123, 1231.123, 12.12, 1);
	/*	}*/
	//}

}

void AEvent::ToggleMuons(){}

int32 AEvent::GetEventNr(){
	return EventNr;
}

int32 AEvent::GetRunNr(){
	return RunNr;
}