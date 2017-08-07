// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "NetServer.generated.h"

USTRUCT(BlueprintType)
struct ATLASRIFT_API FNetServer {
	GENERATED_USTRUCT_BODY()
	
		UPROPERTY(BlueprintReadOnly)
			FString accessCode;
		UPROPERTY(BlueprintReadOnly)
			FString ip;
		UPROPERTY(BlueprintReadOnly)
			FString description;
		UPROPERTY(BlueprintReadOnly)
			int32 clients;
};