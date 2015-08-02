// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ATLASrift.h"
#include "ATLASrift.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeATLASrift() {}
	void ATrack::StaticRegisterNativesATrack()
	{
	}
	IMPLEMENT_CLASS(ATrack, 3904564520);
	void AEvent::StaticRegisterNativesAEvent()
	{
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"GetEvent",(Native)&AEvent::execGetEvent);
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"SpawnTracks",(Native)&AEvent::execSpawnTracks);
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"ToggleMuons",(Native)&AEvent::execToggleMuons);
	}
	IMPLEMENT_CLASS(AEvent, 2239635335);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();

	ATLASRIFT_API class UClass* Z_Construct_UClass_ATrack_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_ATrack();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_GetEvent();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_SpawnTracks();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_ToggleMuons();
	ATLASRIFT_API class UClass* Z_Construct_UClass_AEvent_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_AEvent();
	ATLASRIFT_API class UPackage* Z_Construct_UPackage_ATLASrift();
	UClass* Z_Construct_UClass_ATrack_NoRegister()
	{
		return ATrack::StaticClass();
	}
	UClass* Z_Construct_UClass_ATrack()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_ATLASrift();
			OuterClass = ATrack::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Track.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Track.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrack(Z_Construct_UClass_ATrack, TEXT("ATrack"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrack);
	UFunction* Z_Construct_UFunction_AEvent_GetEvent()
	{
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetEvent"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Event Functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Event.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AEvent_SpawnTracks()
	{
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SpawnTracks"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Event Functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Event.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AEvent_ToggleMuons()
	{
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ToggleMuons"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Event Functions"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Event.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEvent_NoRegister()
	{
		return AEvent::StaticClass();
	}
	UClass* Z_Construct_UClass_AEvent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_ATLASrift();
			OuterClass = AEvent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_GetEvent());
				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_SpawnTracks());
				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_ToggleMuons());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_EventNr = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("EventNr"), RF_Public|RF_Transient|RF_Native) UUInt32Property(CPP_PROPERTY_BASE(EventNr, AEvent), 0x0000000000000000);
				UProperty* NewProp_RunNr = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RunNr"), RF_Public|RF_Transient|RF_Native) UUInt32Property(CPP_PROPERTY_BASE(RunNr, AEvent), 0x0000000000000000);
				UProperty* NewProp_Track = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Track"), RF_Public|RF_Transient|RF_Native) UClassProperty(CPP_PROPERTY_BASE(Track, AEvent), 0x0004000000010001, Z_Construct_UClass_ATrack_NoRegister());
				UProperty* NewProp_TargetHost = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TargetHost"), RF_Public|RF_Transient|RF_Native) UStrProperty(CPP_PROPERTY_BASE(TargetHost, AEvent), 0x0000000000010001);
PRAGMA_POP
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_GetEvent()); // 3848012069
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_SpawnTracks()); // 1209136393
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_ToggleMuons()); // 2134651739
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Event.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_EventNr, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_RunNr, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_Track, TEXT("Category"), TEXT("Tracks"));
				MetaData->SetValue(NewProp_Track, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_TargetHost, TEXT("Category"), TEXT("EventServer"));
				MetaData->SetValue(NewProp_TargetHost, TEXT("ModuleRelativePath"), TEXT("Event.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEvent(Z_Construct_UClass_AEvent, TEXT("AEvent"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEvent);
	UPackage* Z_Construct_UPackage_ATLASrift()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/ATLASrift")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0x5A49BCB9;
			Guid.B = 0xDE05D1BD;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
