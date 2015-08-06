// Fill out your copyright notice in the Description page of Project Settings.

#include "ATLASrift.h"
#include "Track.h"

ATrack::ATrack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void ATrack::SetParameters(float x, float y, float z, bool ch){
	px = x;
	py = y;
	pz = z;
	charge = ch;
}

