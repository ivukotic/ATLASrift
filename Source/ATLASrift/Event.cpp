// Fill out your copyright notice in the Description page of Project Settings.


#include "ATLASrift.h"
#include "Json.h"
#include "ParticleDefinitions.h"
#include "Event.h"
#include "Cluster.h"
#include "Jet.h"
#include "Track.h"

DEFINE_LOG_CATEGORY(EventLog);

AEvent::AEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TargetHost = "http://atlasrift.appspot.com/";
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
	fullURL.Append("eventserver?eventid=").Append(FString::FromInt(eventID%totalEvents));
	UE_LOG(EventLog, Display, TEXT("asking for: %s"), *fullURL);

	Request->SetURL(fullURL);
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Accept", "application/json");

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
		TSharedPtr<FJsonObject> jEvent;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(MessageBody);
		if (FJsonSerializer::Deserialize(JsonReader, jEvent))
		{
            RunNr = jEvent->GetNumberField("runnr");
			EventNr = jEvent->GetNumberField("eventnr");
			Description = jEvent->GetStringField("description");
			UE_LOG(EventLog, Display, TEXT("run: %d event: %d"), RunNr, EventNr);

            TSharedPtr<FJsonObject> jClusters = jEvent->GetObjectField("xAOD::Type::CaloCluster");
            
            for (auto currJsonValue = jClusters->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
            {
                const FString ClusterTypeName = (*currJsonValue).Key;
				ClusterTypes.Add(ClusterTypeName);
                
                // Get the array of clusters as a FJsonValue object
                TSharedPtr< FJsonValue > ClusterArray = (*currJsonValue).Value;
				TArray<TSharedPtr<FJsonValue>> clusters = ClusterArray->AsArray();
				UE_LOG(EventLog, Display, TEXT("cluster type: %s clusters: %d "), *ClusterTypeName, clusters.Num() );
				for (int32 i = 0; i < clusters.Num(); i++)
				{
					FJsonObject re = *clusters[i]->AsObject();
					//EventSpawnLoc = GetCartesianFromPolar(new FVector(re.GetNumberField("eta"), re.GetNumberField("phi"), 500.0f));
					EventSpawnLoc = GetCartesianFromPolar(new FVector(0.0f, 0.0f, 0.0f));
					//UE_LOG(EventLog, Display, TEXT("cluster phi: %f eta: %f "), re.GetNumberField("phi"), re.GetNumberField("eta"));
					ACluster* cl = (ACluster*) GetWorld()->SpawnActor(ACluster::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
					cl->phi = re.GetNumberField("phi");
					cl->eta = re.GetNumberField("eta");
					cl->energy = re.GetNumberField("energy");

				}
            }
            

            TSharedPtr<FJsonObject> jJets = jEvent->GetObjectField("xAOD::Type::Jet");
			for (auto currJsonValue = jJets->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
			{
				const FString JetTypeName = (*currJsonValue).Key;
				ClusterTypes.Add(JetTypeName);

				// Get the array of jests as a FJsonValue object
				TSharedPtr< FJsonValue > JetArray = (*currJsonValue).Value;
				TArray<TSharedPtr<FJsonValue>> jets = JetArray->AsArray();
				UE_LOG(EventLog, Display, TEXT("jet type: %s jets: %d "), *JetTypeName, jets.Num());
				for (int32 i = 0; i < jets.Num(); i++)
				{
					FJsonObject re = *jets[i]->AsObject();
					float eta = re.GetNumberField("eta");
					float phi = re.GetNumberField("phi");
					EventSpawnLoc = GetCartesianFromPolar(new FVector(eta, phi, 0.0f));
					EventSpawnRotation = new FRotator(GetTethaFromEta(eta)*57.2957795, 0.0f, phi*57.2957795);
					//UE_LOG(EventLog, Display, TEXT("cluster phi: %f eta: %f "), phi, eta);
					AJet* jet = (AJet*)GetWorld()->SpawnActor(AJet::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
					jet->phi = phi;
					jet->eta = eta;
					jet->energy = re.GetNumberField("energy");
					jet->coneR = re.GetNumberField("coneR");

				}
			}

            TSharedPtr<FJsonObject> jTracks = jEvent->GetObjectField("xAOD::Type::TrackParticle");
			for (auto currJsonValue = jTracks->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
			{
				const FString TrackTypeName = (*currJsonValue).Key;
				ClusterTypes.Add(TrackTypeName);

				// Get the array of tracks as a FJsonValue object
				TSharedPtr< FJsonValue > TrackArray = (*currJsonValue).Value;
				TArray<TSharedPtr<FJsonValue>> tracks = TrackArray->AsArray();
				UE_LOG(EventLog, Display, TEXT("jet type: %s jets: %d "), *TrackTypeName, tracks.Num());
				for (int32 i = 0; i < tracks.Num(); i++)
				{
					FJsonObject re = *tracks[i]->AsObject();
					EventSpawnLoc = new FVector(0.0f, 0.0f, 0.0f);
					ATrack* track = (ATrack*)GetWorld()->SpawnActor(ATrack::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
					track->dof = re.GetIntegerField("dof");
					track->chi2 = re.GetNumberField("chi2");
					//TSharedPtr< FJsonValue > dparams = re.GetArrayField("dparams");
					//TArray<TSharedPtr<FJsonValue>> dps = dparams->AsArray();
					TArray<TSharedPtr<FJsonValue>> dps = re.GetArrayField("dparams");
					track->d0 = dps[0]->AsNumber();
					track->z0 = dps[1]->AsNumber();
					track->phi = dps[2]->AsNumber();
					track->theta = dps[3]->AsNumber();
					track->qop = dps[4]->AsNumber();

				}
			}

		}
	}
	else
	{
		UE_LOG(EventLog, Error, TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
	onEventDownloaded();
}
float AEvent::GetTethaFromEta(float eta)
{
	return 2.0 * atan(exp(-eta));
}
// polar coordinate will be given as eta, phi, r 
// returns coordinates transformed for Unreal
FVector * AEvent::GetCartesianFromPolar(FVector* polar)
{
	float eta = polar->X;
	float fi = polar->Y;
	float r = polar->Z;

	float Theta = 2.0 * atan(exp(-eta));
	// FVector* ret = new FVector(r*cos(fi), r*sin(fi), r*cos(Theta)); real coordinates
	FVector* ret = new FVector(r*cos(Theta), -r*cos(fi), r*sin(fi) ); // unreal coordinates

	return ret;
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