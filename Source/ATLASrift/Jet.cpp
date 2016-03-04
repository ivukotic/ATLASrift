// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Jet.h"


// Sets default values
AJet::AJet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	smc = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("smc text"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/Misc/cone'"));
	static ConstructorHelpers::FObjectFinder <UMaterialInterface> Material_Blue(TEXT("Material'/Game/Materials/M_Metal_Red'"));
	smc->SetStaticMesh(StaticMesh.Object);
	smc->SetMaterial(0, Material_Blue.Object);
	RootComponent = smc;
}

void AJet::setScale(float scale)
{
	FVector Scale = FVector(scale);
	smc->SetWorldScale3D(Scale);
}