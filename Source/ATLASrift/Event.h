// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Track.h"
#include "Http.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Event.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EventLog, Log, All);
/**
 * 
 */


USTRUCT()
struct FEventState
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		BOOL ShowTracks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		BOOL ShowJets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		BOOL ShowClusters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		BOOL AutoReload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		BOOL ChangeToPreviousEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		BOOL ChangeToNextEvent;

	FEventState()
	{
		ShowTracks = true;
		ShowJets = true;
		ShowClusters = true;
		AutoReload = false;
		ChangeToPreviousEvent = false;
		ChangeToNextEvent = false;
	}

};


UCLASS()
class ATLASRIFT_API AEvent : public AActor
{
	GENERATED_BODY()

	AEvent(const FObjectInitializer& ObjectInitializer);
	FHttpModule* Http;

	UPROPERTY(EditDefaultsOnly, Category = "EventServer")
		FString TargetHost;

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

//	UFUNCTION(BlueprintCallable, Category = "Geometry Transformation Functions")
	FVector* GetCartesianFromPolar(FVector* polar);
	int32 RunNr;
	int32 EventNr;

	int32 totalEvents;
	FString Description;
	TArray<FString> TrackTypes;
	TArray<FString> ClusterTypes;
	TArray<FString> JetTypes;
	FVector* EventSpawnLoc;
	FRotator* EventSpawnRotation;
	FActorSpawnParameters SpawnInfo;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float percentLoad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		UMaterial* ClusterMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		UMaterial* TrackMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FVector> normals;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FVector2D> UV0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FColor> vertexColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FProcMeshTangent> tangents;

	UPROPERTY(BlueprintReadWrite, Category = "Event Properties")
		int32 eventID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventServer")
		float Phi;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventServer")
		float Theta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventServer")
		float Energy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		int32 currentVertexIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		int32 currentVertexIndexX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		int32 currentVertexIndexY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<int32> Triangles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<int32> TrianglesX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<int32> TrianglesY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<int32> VertexPattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FVector> Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FVector> Vertices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FVector> VerticesX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		TArray<FVector> VerticesY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FEventState EventState;

	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Jet elements")
		TArray<TSubclassOf<class AJet> > Jets;
	UPROPERTY(BlueprintReadOnly, Category = "Track elements")
		UProceduralMeshComponent* meshX;
	UPROPERTY(BlueprintReadOnly, Category = "Track elements")
		UProceduralMeshComponent* meshY;
	UPROPERTY(BlueprintReadOnly, Category = "Cluster elements")
		UProceduralMeshComponent* meshCluster;

	UFUNCTION(BlueprintImplementableEvent, Category = "EventServer")
		void onEventDownloaded();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		int32 GetEventNr();
	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void ShowTracksFunc();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		int32 GetRunNr();
	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		FString GetDescription();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void GetEvent();
	
	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void AddTris();

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void Add4Points(float energy1);

	UFUNCTION(BlueprintCallable, Category = "Event Functions")
		void ShowClustersFunc();

	UFUNCTION(BlueprintCallable, Category = "Geometry Transformation Functions")
		float GetTethaFromEta(float eta);

};
