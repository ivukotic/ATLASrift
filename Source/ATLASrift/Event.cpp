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
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;

	this->SetActorTickEnabled(true);
	TargetHost = "http://atlasrift.appspot.com/";
	Http = &FHttpModule::Get();
    eventID=0;
	Phi = 0;
	Theta = 0;
	Energy = 0;

	int32 temp[] = { 0, 2, 1, 0, 3, 2,
		4, 5, 6, 4, 6, 7,
		0, 5, 4, 0, 1, 5,
		0, 4, 7, 0, 7, 3,
		1, 6, 5, 1, 2, 6,
		2, 7, 6, 2, 3, 7 };

	for (int i = 0; i < 36; i++)
		VertexPattern.Add(temp[i]);

	Points.Add(FVector(-0.03f, -0.03f, 0.0f));
	Points.Add(FVector(0.03f, -0.03f, 0.0f));
	Points.Add(FVector(0.03f, 0.03f, 0.0f));
	Points.Add(FVector(-0.03f, 0.03f, 0.0f));

	Vertices.Add(FVector(-0.03f, -0.03f, 0.0f));
	Vertices.Add(FVector(0.03f, -0.03f, 0.0f));
	Vertices.Add(FVector(0.03f, 0.03f, 0.0f));
	Vertices.Add(FVector(-0.03f, 0.03f, 0.0f));

    totalEvents=1;

	EventSpawnLoc = new FVector(0.0f, 0.0f, 0.0f);
	EventSpawnRotation = new FRotator(0.0f, 0.0f, 0.0f);
	SpawnInfo.Owner = this;
	SpawnInfo.bDeferConstruction = false;
	meshX = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	meshY = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh1"));
	meshCluster = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedCluster"));
	trackDataLoadComplete = false;
	UE_LOG(EventLog, Error, TEXT("Set trackDataLoadComplete = false"));

	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	vertexColors.Add(FColor(100, 100, 100, 100));
	vertexColors.Add(FColor(100, 100, 100, 100));
	vertexColors.Add(FColor(100, 100, 100, 100));

	tangents.Add(FProcMeshTangent(1, 1, 1));
	tangents.Add(FProcMeshTangent(1, 1, 1));
	tangents.Add(FProcMeshTangent(1, 1, 1));
	//GetWorld()->SpawnActor<ATrack>(Tracks[0]);
	percentLoad = 0;
	dataload = false;
	tickGap = 1;
	tickCounter = 0;
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
					//UE_LOG(EventLog, Display, TEXT("cluster phi: %f eta: %f "), re.GetNumberField("phi"), re.GetNumberField("eta"));
					ACluster* cl = (ACluster*) GetWorld()->SpawnActor(ACluster::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
					cl->phi = re.GetNumberField("phi");
					cl->eta = re.GetNumberField("eta");
					cl->theta = GetTethaFromEta(cl->eta);
					cl->energy = re.GetNumberField("energy");

				}
            }
            

            TSharedPtr<FJsonObject> jJets = jEvent->GetObjectField("xAOD::Type::Jet");
			for (auto currJsonValue = jJets->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
			{
				const FString JetTypeName = (*currJsonValue).Key;
				JetTypes.Add(JetTypeName);

				// Get the array of jets as a FJsonValue object
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
				TrackTypes.Add(TrackTypeName);

				// Get the array of tracks as a FJsonValue object
				TSharedPtr< FJsonValue > TrackArray = (*currJsonValue).Value;
				TArray<TSharedPtr<FJsonValue>> tracks = TrackArray->AsArray();
				UE_LOG(EventLog, Display, TEXT("track type: %s tracks: %d "), *TrackTypeName, tracks.Num());
				for (int32 i = 0; i < tracks.Num(); i++)
				{
					FJsonObject re = *tracks[i]->AsObject();
					EventSpawnLoc = new FVector(0.0f, 0.0f, 0.0f);
					EventSpawnRotation = new FRotator(0.0f, 0.0f, 0.0f);
					ATrack* track = (ATrack*)GetWorld()->SpawnActor(ATrack::StaticClass(), EventSpawnLoc, EventSpawnRotation, SpawnInfo);
					track->dof = re.GetIntegerField("dof");
					track->chi2 = re.GetNumberField("chi2");
					TArray<TSharedPtr<FJsonValue>> dps = re.GetArrayField("dparams");
					track->d0 = dps[0]->AsNumber();
					track->z0 = dps[1]->AsNumber();
					track->phi = dps[2]->AsNumber();
					track->theta = dps[3]->AsNumber();
					track->qop = dps[4]->AsNumber();
					TArray<TSharedPtr<FJsonValue>> pos = re.GetArrayField("pos"); 
					for (int32 v = 0; v < pos.Num(); v++)
					{
						TArray<TSharedPtr<FJsonValue>> po = pos[v]->AsArray();
						track->points.Add(FVector(po[2]->AsNumber()*0.1, po[0]->AsNumber()*0.1, po[1]->AsNumber()*0.1));
					}
				}
			}

		}
	}
	else
	{
		UE_LOG(EventLog, Error, TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
	dataload = true;
	onEventDownloaded();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("oneventdowload called!"));


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


void AEvent::ShowTracksFunc()
{
	Vertices.Reset();
	VerticesX.Reset();
	VerticesY.Reset();
	Triangles.Reset();
	TrianglesX.Reset();
	TrianglesY.Reset();

	currentVertexIndexX = 0;
	currentVertexIndexY = 0;
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("ShowTracks is called！")));
	
	for (TActorIterator<ATrack> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->points.Num()*percentLoad > 1)
		{
			int counter = 0;
			for (FVector var : ActorItr->points)
			{
				if (counter < ActorItr->points.Num()*percentLoad)
				{
					counter++;
					VerticesX.Add(FVector(var.X + 0.5, var.Y, var.Z));
					VerticesX.Add(FVector(var.X - 0.5, var.Y, var.Z));
					VerticesY.Add(FVector(var.X, var.Y + 0.5, var.Z));
					VerticesY.Add(FVector(var.X, var.Y - 0.5, var.Z));

					UE_LOG(EventLog, Error, TEXT("x=: %f, y= %f, z=%f"), var.X, var.Y, var.Z);
				}
			}

			//		UE_LOG(EventLog, Error, TEXT("before Vertices.Num()= %d "), Vertices.Num());
			//		Vertices.Append(ActorItr->points);
			//		UE_LOG(EventLog, Error, TEXT("after Vertices.Num()= %d "), Vertices.Num());
			for (int i = 0; i < VerticesX.Num() - currentVertexIndexX - 2; i = i + 2)
			{

				TrianglesX.Add(currentVertexIndexX + i);
				TrianglesX.Add(i + 1 + currentVertexIndexX);
				TrianglesX.Add(i + 2 + currentVertexIndexX);
				TrianglesX.Add(i + 2 + currentVertexIndexX);
				TrianglesX.Add(i + 1 + currentVertexIndexX);
				TrianglesX.Add(currentVertexIndexX + i);

				TrianglesX.Add(i + 1 + currentVertexIndexX);
				TrianglesX.Add(i + 3 + currentVertexIndexX);
				TrianglesX.Add(i + 2 + currentVertexIndexX);
				TrianglesX.Add(i + 2 + currentVertexIndexX);
				TrianglesX.Add(i + 3 + currentVertexIndexX);
				TrianglesX.Add(i + 1 + currentVertexIndexX);

			}

			for (int i = 0; i < VerticesY.Num() - currentVertexIndexY - 2; i = i + 2)
			{

				TrianglesY.Add(currentVertexIndexY + i);
				TrianglesY.Add(i + 1 + currentVertexIndexY);
				TrianglesY.Add(i + 2 + currentVertexIndexY);
				TrianglesY.Add(i + 2 + currentVertexIndexY);
				TrianglesY.Add(i + 1 + currentVertexIndexY);
				TrianglesY.Add(currentVertexIndexY + i);

				TrianglesY.Add(i + 1 + currentVertexIndexY);
				TrianglesY.Add(i + 3 + currentVertexIndexY);
				TrianglesY.Add(i + 2 + currentVertexIndexY);
				TrianglesY.Add(i + 2 + currentVertexIndexY);
				TrianglesY.Add(i + 3 + currentVertexIndexY);
				TrianglesY.Add(i + 1 + currentVertexIndexY);

			}

			currentVertexIndexX = VerticesX.Num();
			currentVertexIndexY = VerticesY.Num();
		}

	}

}


// Called every frame
void AEvent::Tick(float DeltaTime)
{
	tickCounter++;
	Super::Tick(DeltaTime);

	if (dataload&&tickCounter>=tickGap)
	{

		percentLoad = percentLoad + 0.01;
		if (percentLoad > 1)
			percentLoad = 0;

		tickCounter = 0;

		ShowTracksFunc();
		if (VerticesX.Num()>0)
		{
			int32 counterTemp = VerticesX.Num();

			TArray<FVector> VerticesXTemp;
			TArray<int32> TrianglesXTemp;
			TArray<FVector> VerticesYTemp;
			TArray<int32> TrianglesYTemp;

			for (int i = 0; i < counterTemp; i++)
			{
				VerticesXTemp.Add(VerticesX[i]);
				VerticesYTemp.Add(VerticesY[i]);
			}
			for (int i = 0; i < 2 * (counterTemp - 4) + 4; i++)
			{
				TrianglesXTemp.Add(TrianglesX[i]);
				TrianglesYTemp.Add(TrianglesY[i]);
			}
			meshX->CreateMeshSection(1, VerticesXTemp, TrianglesXTemp, normals, UV0, vertexColors, tangents, false);
			meshY->CreateMeshSection(1, VerticesYTemp, TrianglesYTemp, normals, UV0, vertexColors, tangents, false);
			meshX->AttachTo(RootComponent);
			meshY->AttachTo(RootComponent);
		}

		for (TActorIterator<AJet> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			ActorItr->setScale(percentLoad);
		}
		ShowClustersFunc(percentLoad);
	}
	
}

void AEvent::AddTris()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("New AddTris is called！")));
	for (INT32 var : VertexPattern)
	{
		Triangles.Add(currentVertexIndex + var);
	}
	currentVertexIndex = currentVertexIndex + 8;
}

void AEvent::ShowClustersFunc(float percentLoad)
{
	Vertices.Reset();
	Triangles.Reset();
	currentVertexIndex = 0;
	for (TActorIterator<ACluster> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		Phi = ActorItr->phi;
		Theta = ActorItr->theta;
		Energy = ActorItr->energy;
		Add4Points(0);
		Add4Points(Energy*percentLoad);
		AddTris();
	}

	meshCluster->CreateMeshSection(1, Vertices, Triangles, normals, UV0, vertexColors, tangents, false);
	meshCluster->AttachTo(RootComponent);
}

void AEvent::Add4Points(float energy1)
{
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("New Add4Points is called！")));
	FVector vect;
	float scale1 = energy1 / 1000 + 320;
	float scale2 = energy1 / 1000 + 207.7;

	for (FVector var : Points)
	{
		float valTemp = Theta + var.X;
		if (valTemp<0.5757 || valTemp>2.5659)
		{
			float sign = -1 * (valTemp - 1.5707963);
			if (sign < 0)
				vect.X = -1;
			if (sign == 0)
				vect.X = 0;
			if (sign > 0)
				vect.X = 1;

			vect.Y = sin(valTemp)*cos(var.Y + Phi);
			vect.Z = sin(valTemp)*sin(var.Y + Phi);
			vect = vect *scale1;
		}
		else
		{
			vect.X = 1.0 / tan(valTemp);
			vect.Y = cos(var.Y + Phi);
			vect.Z = sin(var.Y + Phi);
			vect = vect*scale2;
		}

		Vertices.Add(vect);

	}

}

// Called when the game starts or when spawned
void AEvent::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;
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


