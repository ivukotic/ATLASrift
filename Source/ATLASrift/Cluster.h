// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "GameFramework/Actor.h"
#include "Cluster.generated.h"

UCLASS()
class ATLASRIFT_API ACluster : public AActor
{
	GENERATED_BODY()
	ACluster(const FObjectInitializer& ObjectInitializer);

public:	

	UPROPERTY(BlueprintReadOnly, Category = "Cluster Parameters")
		float phi;
	UPROPERTY(BlueprintReadOnly, Category = "Cluster Parameters")
		float eta;
	UPROPERTY(BlueprintReadOnly, Category = "Cluster Parameters")
		float energy;
	
	
};
