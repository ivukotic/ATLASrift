// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "GameFramework/Actor.h"
#include "Jet.generated.h"

UCLASS()
class ATLASRIFT_API AJet : public AActor
{
	GENERATED_BODY()
	
	AJet(const FObjectInitializer& ObjectInitializer);

public:	
	UPROPERTY(BlueprintReadOnly, Category = "Jet Parameters")
		float coneR;
	UPROPERTY(BlueprintReadOnly, Category = "Jet Parameters")
		float phi;
	UPROPERTY(BlueprintReadOnly, Category = "Jet Parameters")
		float eta;
	UPROPERTY(BlueprintReadOnly, Category = "Jet Parameters")
		float energy;

	UStaticMeshComponent* smc;
	
};
