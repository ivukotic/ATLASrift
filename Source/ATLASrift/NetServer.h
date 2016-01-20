// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "NetServer.generated.h"

/**
 * 
 */
UCLASS()
class ATLASRIFT_API UNetServer : public UUserDefinedStruct
{
	GENERATED_BODY()

public:
	FString hostname;
	FString ip;
	FString description;
	
	
	
};
