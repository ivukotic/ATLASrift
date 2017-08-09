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

}

void ATrack::SetParameters(float _d0, float _z0, float _phi, float _theta, float _qop){
	this->d0 = _d0;
	this->z0 = _z0;
	this->phi = _phi;
	this->theta = _theta;
	this->qop = _qop;
}

//TArray<FVector> ATrack::GetVertices()
//{
//	TArray<FVector> ret;
//	return ret;
//}
//
//TArray<int32> ATrack::GetTriangles(int32 currentVertex)
//{
//	TArray<int32> ret;
//	return ret;
//}

