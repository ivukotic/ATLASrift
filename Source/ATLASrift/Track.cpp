// Fill out your copyright notice in the Description page of Project Settings.

#include "ATLASrift.h"
#include "Track.h"

DEFINE_LOG_CATEGORY(TrackLog);

ATrack::ATrack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//RootComponent = SphereComponent;

	/**
	*	Create/replace a section for this procedural mesh component.
	*	@param	SectionIndex		Index of the section to create or replace.
	*	@param	Vertices			Vertex buffer of all vertex positions to use for this mesh section.
	*	@param	Triangles			Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3.
	*	@param	Normals				Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	UV0					Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array.
	*	@param	VertexColors		Optional array of colors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	Tangents			Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array.
	*	@param	bCreateCollision	Indicates whether collision should be created for this section. This adds significant cost.
	*/

	//TArray<FVector> vertices;

	//vertices.Add(FVector(0, 0, 0));
	//vertices.Add(FVector(0, 100, 0));
	//vertices.Add(FVector(0, 0, 100));

	//TArray<int32> Triangles;
	//Triangles.Add(0);
	//Triangles.Add(1);
	//Triangles.Add(2);

	//TArray<FVector> normals;
	//normals.Add(FVector(1, 0, 0));
	//normals.Add(FVector(1, 0, 0));
	//normals.Add(FVector(1, 0, 0));

	//TArray<FVector2D> UV0;
	//UV0.Add(FVector2D(0, 0));
	//UV0.Add(FVector2D(0, 10));
	//UV0.Add(FVector2D(10, 10));

	//TArray<FColor> vertexColors;
	//vertexColors.Add(FColor(100, 100, 100, 100));
	//vertexColors.Add(FColor(100, 100, 100, 100));
	//vertexColors.Add(FColor(100, 100, 100, 100));


	//TArray<FProcMeshTangent> tangents;
	//tangents.Add(FProcMeshTangent(1, 1, 1));
	//tangents.Add(FProcMeshTangent(1, 1, 1));
	//tangents.Add(FProcMeshTangent(1, 1, 1));


}

void ATrack::SetParameters(float d0, float z0, float phi, float theta, float qop){
	this->d0 = d0;
	this->z0 = z0;
	this->phi = phi;
	this->theta = theta;
	this->qop = qop;
}

TArray<FVector> ATrack::GetVertices()
{
	TArray<FVector> ret;
	ret.Add(FVector(0.0,0.0,0.0));
	ret.Add(FVector(phi*500, theta * 500, phi * 500));
	ret.Add(FVector(theta * 500, phi * 500,theta * 500));
	UE_LOG(TrackLog, Display, TEXT("track vertex phi : %f theta: %f "), phi * 500.0, theta * 500);
	return ret;
}

TArray<int32> ATrack::GetTriangles(int32 currentVertex)
{
	TArray<int32> ret;
	UE_LOG(TrackLog, Display, TEXT("triangle starts from : %d "), currentVertex);
	ret.Add(currentVertex + 0);
	ret.Add(currentVertex + 1);
	ret.Add(currentVertex + 2);
	return ret;
}

