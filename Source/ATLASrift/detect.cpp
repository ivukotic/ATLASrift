// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "detect.h"
#include "HeadMountedDisplayTypes.h"
#include "IHeadMountedDisplay.h"

// Sets default values
Adetect::Adetect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Adetect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Adetect::Tick( float DeltaTime )
{
	//Super::Tick( DeltaTime );

}

uint8 Adetect::HMDtype()
{
	if (GEngine->HMDDevice.IsValid()) //check pointer is valid
	{
		uint8 result = (uint8)GEngine->HMDDevice->GetHMDDeviceType();
		if (result == (uint8)EHMDDeviceType::DT_OculusRift) {
			UE_LOG(LogTemp, Warning, TEXT("Device is Rift"));
			return result;
		}
		if (result == (uint8)EHMDDeviceType::DT_Morpheus) {
			UE_LOG(LogTemp, Warning, TEXT("Device is Morpheus"));
			return result;
		}
		UE_LOG(LogTemp, Warning, TEXT("Device is Other"));
		return result;
	}
	else 	UE_LOG(LogTemp, Error, TEXT("No device found!"));
	return 99;
}

bool Adetect ::HMDisEnabled()
{
	return GEngine->HMDDevice->IsHMDEnabled();
}

bool Adetect::HMDhasFocus()
{
	return GEngine->HMDDevice->DoesAppHaveVRFocus();
}

bool Adetect::HMDisConnected()
{
	return GEngine && GEngine->HMDDevice->IsHMDConnected();
}