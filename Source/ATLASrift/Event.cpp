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
	GetEvent();
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("ERROR on processing request!"));
	}
}
void AEvent::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

	FString MessageBody = "";
	// If HTTP fails client-side, this will still be called but with a NULL shared pointer!
	if (!Response.IsValid())
	{
		MessageBody = "{\"success\":\"Error: Unable to get event!\"}";
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		MessageBody = Response->GetContentAsString();

		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(MessageBody);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			uint32 runnr = JsonParsed->GetNumberField("run");
			uint32 eventnr = JsonParsed->GetNumberField("event");
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("{\"run: %d event: %d\"}"), runnr, eventnr));
		}
	}
	else
	{
		MessageBody = FString::Printf(TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
}

void AEvent::SpawnTracks(){
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoCollisionFail = true;
	SpawnInfo.Owner = this;
	SpawnInfo.bDeferConstruction = false;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Generating Tracks"));
	}

	//for (int x = 0; x < 10; x++)
	//{
	//	for (int y = 0; y < 10; y++)
	//	{
			FVector EventSpawnLoc(0.0f, 0.0f, 0.0f);
			FRotator EventSpawnRotation(0.0f, 0.0f, 0.0f);
			ATrack* NewTrack = AEvent::GetWorld()->SpawnActor<ATrack>(Track, EventSpawnLoc, EventSpawnRotation, SpawnInfo);
	//	}
	//}

}

void AEvent::ToggleMuons(){}

