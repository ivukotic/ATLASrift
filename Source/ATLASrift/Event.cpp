// Fill out your copyright notice in the Description page of Project Settings.


#include "ATLASrift.h"
#include "Json.h"
#include "ParticleDefinitions.h"
#include "Event.h"
#include "Cluster.h"

DEFINE_LOG_CATEGORY(EventLog);

AEvent::AEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TargetHost = "http://cl-analytics.mwt2.org:9200/";
	Http = &FHttpModule::Get();
    eventID=0;
    totalEvents=1;
	EventSpawnLoc = new FVector(0.0f, 0.0f, 0.0f);
	EventSpawnRotation = new FRotator(0.0f, 0.0f, 0.0f);
	SpawnInfo.Owner = this;
	SpawnInfo.bDeferConstruction = false;

	//GetWorld()->SpawnActor<ATrack>(Tracks[0]);
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
	FString fullURL = TargetHost;
	fullURL.Append("atlasrift_events/event/").Append(FString::FromInt(eventID%totalEvents));
	UE_LOG(EventLog, Display, TEXT("asking for: %s"), *fullURL);

	Request->SetURL(fullURL);
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
//	Request->SetHeader("Content-Type", "application/json");
	Request->SetHeader("Accept", "application/json");
//	Request->SetContentAsString("{\"query\":{\"match_all\":{}}}");

	Request->OnProcessRequestComplete().BindUObject(this, &AEvent::OnResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(EventLog, Error, TEXT("Error on getting event."));
	}
}

void AEvent::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	UE_LOG(EventLog, Display, TEXT("got something"));
	FString MessageBody = "";
	// If HTTP fails client-side, this will still be called but with a NULL shared pointer!
	if (!Response.IsValid())
	{
		UE_LOG(EventLog, Error, TEXT("Error on getting event payload."));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		MessageBody = Response->GetContentAsString();
		TSharedPtr<FJsonObject> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(MessageBody);
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			
            TSharedPtr<FJsonObject> jEvent = JsonParsed->GetObjectField("_source");
            RunNr = jEvent->GetNumberField("runnr");
			EventNr = jEvent->GetNumberField("eventnr");
			Description = jEvent->GetStringField("description");
			UE_LOG(EventLog, Display, TEXT("run: %d event: %d"), RunNr, EventNr);

            TSharedPtr<FJsonObject> jClusters = jEvent->GetObjectField("xAOD::Type::CaloCluster");
            
            for (auto currJsonValue = jClusters->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
            {
                const FString ClusterTypeName = (*currJsonValue).Key;
				ClusterTypes.Add(ClusterTypeName);
				UE_LOG(EventLog, Display, TEXT("cluster type: %s "), *ClusterTypeName);
                
                // Get the array of clusters as a FJsonValue object
                TSharedPtr< FJsonValue > ClusterArray = (*currJsonValue).Value;
				TArray<TSharedPtr<FJsonValue>> clusters = ClusterArray->AsArray();
				UE_LOG(EventLog, Display, TEXT("clusters: %d "), clusters.Num() );
				for (int32 i = 0; i < clusters.Num(); i++)
				{
					FJsonObject re = *clusters[i]->AsObject();
					EventSpawnLoc = new FVector(re.GetNumberField("phi")*500.0f, re.GetNumberField("eta")*500.0f, 0.0f);
					//UE_LOG(EventLog, Display, TEXT("cluster phi: %f eta: %f "), re.GetNumberField("phi"), re.GetNumberField("eta"));
					ACluster* cl = (ACluster*) GetWorld()->SpawnActor(ACluster::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
					cl->phi = re.GetNumberField("phi");
					cl->eta = re.GetNumberField("eta");
					cl->energy = re.GetNumberField("energy");

				}
            }
            

            TSharedPtr<FJsonObject> jJets = jEvent->GetObjectField("xAOD::Type::Jet");
            TSharedPtr<FJsonObject> jTracks = jEvent->GetObjectField("xAOD::Type::TrackParticle");
			

		}
	}
	else
	{
		UE_LOG(EventLog, Error, TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
	onEventDownloaded();
}



int32 AEvent::GetEventNr(){
	return EventNr;
}

int32 AEvent::GetRunNr(){
	return RunNr;
}

FString AEvent::GetDescription(){
	return Description;
}