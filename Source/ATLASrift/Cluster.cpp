// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Cluster.h"


ACluster::ACluster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//smc = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("smc text"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/Misc/cube.cube'"));
	//static ConstructorHelpers::FObjectFinder<UMaterial> Material_Blue(TEXT("MaterialInstanceConstant'/Game/StarterContent/props/Materials/M_MaterialSphere_plain.M_MaterialSphere_plain'"));
	//smc->SetStaticMesh(StaticMesh.Object);
	//smc->SetMaterial(0, Material_Blue.Object);
	//RootComponent = smc;
}

