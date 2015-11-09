// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Cluster.h"


ACluster::ACluster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	smc = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("smc text"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/StarterContent/props/MaterialSphere.MaterialSphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> Material_Blue(TEXT("MaterialInstanceConstant'/Game/StarterContent/props/Materials/M_MaterialSphere.M_MaterialSphere'"));
	smc->SetStaticMesh(StaticMesh.Object);
	smc->SetMaterial(0, Material_Blue.Object);
	RootComponent = smc;
}

