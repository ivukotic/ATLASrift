// Fill out your copyright notice in the Description page of Project Settings.

#include "ATLASrift.h"
#include "Track.h"

ATrack::ATrack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void ATrack::SetParameters(float d0, float z0, float phi, float theta, float qop){
	this->d0 = d0;
	this->z0 = z0;
	this->phi = phi;
	this->theta = theta;
	this->qop = qop;
}

