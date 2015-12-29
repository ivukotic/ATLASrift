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
	void ACluster::StaticRegisterNativesACluster()
	{
	}
	IMPLEMENT_CLASS(ACluster, 551827357);
	void ATrack::StaticRegisterNativesATrack()
	{
	}
	IMPLEMENT_CLASS(ATrack, 2630441295);
	void AEvent::onEventDownloaded()
	{
		ProcessEvent(FindFunctionChecked(ATLASRIFT_onEventDownloaded),NULL);
	}
	void AEvent::StaticRegisterNativesAEvent()
	{
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"GetDescription",(Native)&AEvent::execGetDescription);
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"GetEvent",(Native)&AEvent::execGetEvent);
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"GetEventNr",(Native)&AEvent::execGetEventNr);
		FNativeFunctionRegistrar::RegisterFunction(AEvent::StaticClass(),"GetRunNr",(Native)&AEvent::execGetRunNr);
	}
	IMPLEMENT_CLASS(AEvent, 3631796638);
	void AJet::StaticRegisterNativesAJet()
	{
	}
	IMPLEMENT_CLASS(AJet, 1421170759);
	void UReporter::StaticRegisterNativesUReporter()
	{
		FNativeFunctionRegistrar::RegisterFunction(UReporter::StaticClass(),"StartWork",(Native)&UReporter::execStartWork);
		FNativeFunctionRegistrar::RegisterFunction(UReporter::StaticClass(),"StopWork",(Native)&UReporter::execStopWork);
	}
	IMPLEMENT_CLASS(UReporter, 2268269756);
FName ATLASRIFT_onEventDownloaded = FName(TEXT("onEventDownloaded"));
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();

	ATLASRIFT_API class UClass* Z_Construct_UClass_ACluster_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_ACluster();
	ATLASRIFT_API class UClass* Z_Construct_UClass_ATrack_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_ATrack();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_GetDescription();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_GetEvent();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_GetEventNr();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_GetRunNr();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_AEvent_onEventDownloaded();
	ATLASRIFT_API class UClass* Z_Construct_UClass_AEvent_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_AEvent();
	ATLASRIFT_API class UClass* Z_Construct_UClass_AJet_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_AJet();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_UReporter_StartWork();
	ATLASRIFT_API class UFunction* Z_Construct_UFunction_UReporter_StopWork();
	ATLASRIFT_API class UClass* Z_Construct_UClass_UReporter_NoRegister();
	ATLASRIFT_API class UClass* Z_Construct_UClass_UReporter();
	ATLASRIFT_API class UPackage* Z_Construct_UPackage_ATLASrift();
	UClass* Z_Construct_UClass_ACluster_NoRegister()
	{
		return ACluster::StaticClass();
	}
	UClass* Z_Construct_UClass_ACluster()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_ATLASrift();
			OuterClass = ACluster::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_energy = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("energy"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(energy, ACluster), 0x0000000000000014);
				UProperty* NewProp_eta = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("eta"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(eta, ACluster), 0x0000000000000014);
				UProperty* NewProp_phi = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("phi"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(phi, ACluster), 0x0000000000000014);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Cluster.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Cluster.h"));
				MetaData->SetValue(NewProp_energy, TEXT("Category"), TEXT("Cluster Parameters"));
				MetaData->SetValue(NewProp_energy, TEXT("ModuleRelativePath"), TEXT("Cluster.h"));
				MetaData->SetValue(NewProp_eta, TEXT("Category"), TEXT("Cluster Parameters"));
				MetaData->SetValue(NewProp_eta, TEXT("ModuleRelativePath"), TEXT("Cluster.h"));
				MetaData->SetValue(NewProp_phi, TEXT("Category"), TEXT("Cluster Parameters"));
				MetaData->SetValue(NewProp_phi, TEXT("ModuleRelativePath"), TEXT("Cluster.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACluster(Z_Construct_UClass_ACluster, TEXT("ACluster"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACluster);
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


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_points = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("points"), RF_Public|RF_Transient|RF_Native) UArrayProperty(CPP_PROPERTY_BASE(points, ATrack), 0x0000000000000000);
				UProperty* NewProp_points_Inner = new(EC_InternalUseOnlyConstructor, NewProp_points, TEXT("points"), RF_Public|RF_Transient|RF_Native) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FVector());
				UProperty* NewProp_qop = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("qop"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(qop, ATrack), 0x0000000000000014);
				UProperty* NewProp_theta = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("theta"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(theta, ATrack), 0x0000000000000014);
				UProperty* NewProp_phi = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("phi"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(phi, ATrack), 0x0000000000000014);
				UProperty* NewProp_z0 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("z0"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(z0, ATrack), 0x0000000000000014);
				UProperty* NewProp_d0 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("d0"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(d0, ATrack), 0x0000000000000014);
				UProperty* NewProp_chi2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chi2"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(chi2, ATrack), 0x0000000000000014);
				UProperty* NewProp_dof = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("dof"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(dof, ATrack), 0x0000000000000014);
				UProperty* NewProp_type = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("type"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(type, ATrack), 0x0000000000000014);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Track.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_points, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_qop, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_qop, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_theta, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_theta, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_phi, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_phi, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_z0, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_z0, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_d0, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_d0, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_chi2, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_chi2, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_dof, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_dof, TEXT("ModuleRelativePath"), TEXT("Track.h"));
				MetaData->SetValue(NewProp_type, TEXT("Category"), TEXT("Track Parameters"));
				MetaData->SetValue(NewProp_type, TEXT("ModuleRelativePath"), TEXT("Track.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrack(Z_Construct_UClass_ATrack, TEXT("ATrack"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrack);
	UFunction* Z_Construct_UFunction_AEvent_GetDescription()
	{
		struct Event_eventGetDescription_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetDescription"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(Event_eventGetDescription_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_Native) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, Event_eventGetDescription_Parms), 0x0000000000000580);
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
	UFunction* Z_Construct_UFunction_AEvent_GetEventNr()
	{
		struct Event_eventGetEventNr_Parms
		{
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetEventNr"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(Event_eventGetEventNr_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, Event_eventGetEventNr_Parms), 0x0000000000000580);
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
	UFunction* Z_Construct_UFunction_AEvent_GetRunNr()
	{
		struct Event_eventGetRunNr_Parms
		{
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetRunNr"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(Event_eventGetRunNr_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, Event_eventGetRunNr_Parms), 0x0000000000000580);
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
	UFunction* Z_Construct_UFunction_AEvent_onEventDownloaded()
	{
		UObject* Outer=Z_Construct_UClass_AEvent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("onEventDownloaded"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("EventServer"));
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

				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_GetDescription());
				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_GetEvent());
				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_GetEventNr());
				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_GetRunNr());
				OuterClass->LinkChild(Z_Construct_UFunction_AEvent_onEventDownloaded());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Jets = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Jets"), RF_Public|RF_Transient|RF_Native) UArrayProperty(CPP_PROPERTY_BASE(Jets, AEvent), 0x0004000000000014);
				UProperty* NewProp_Jets_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Jets, TEXT("Jets"), RF_Public|RF_Transient|RF_Native) UClassProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0004000000000000, Z_Construct_UClass_AJet_NoRegister());
				UProperty* NewProp_Clusters = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Clusters"), RF_Public|RF_Transient|RF_Native) UArrayProperty(CPP_PROPERTY_BASE(Clusters, AEvent), 0x0004000000000014);
				UProperty* NewProp_Clusters_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Clusters, TEXT("Clusters"), RF_Public|RF_Transient|RF_Native) UClassProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0004000000000000, Z_Construct_UClass_ACluster_NoRegister());
				UProperty* NewProp_Tracks = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Tracks"), RF_Public|RF_Transient|RF_Native) UArrayProperty(CPP_PROPERTY_BASE(Tracks, AEvent), 0x0004000000000014);
				UProperty* NewProp_Tracks_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Tracks, TEXT("Tracks"), RF_Public|RF_Transient|RF_Native) UClassProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0004000000000000, Z_Construct_UClass_ATrack_NoRegister());
				UProperty* NewProp_TargetHost = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TargetHost"), RF_Public|RF_Transient|RF_Native) UStrProperty(CPP_PROPERTY_BASE(TargetHost, AEvent), 0x0000000000010001);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_GetDescription()); // 441737443
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_GetEvent()); // 3848012069
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_GetEventNr()); // 707475995
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_GetRunNr()); // 2090436829
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AEvent_onEventDownloaded()); // 2873975365
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Event.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_Jets, TEXT("Category"), TEXT("Event elements"));
				MetaData->SetValue(NewProp_Jets, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_Clusters, TEXT("Category"), TEXT("Event elements"));
				MetaData->SetValue(NewProp_Clusters, TEXT("ModuleRelativePath"), TEXT("Event.h"));
				MetaData->SetValue(NewProp_Tracks, TEXT("Category"), TEXT("Event elements"));
				MetaData->SetValue(NewProp_Tracks, TEXT("ModuleRelativePath"), TEXT("Event.h"));
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
	UClass* Z_Construct_UClass_AJet_NoRegister()
	{
		return AJet::StaticClass();
	}
	UClass* Z_Construct_UClass_AJet()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_ATLASrift();
			OuterClass = AJet::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_energy = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("energy"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(energy, AJet), 0x0000000000000014);
				UProperty* NewProp_eta = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("eta"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(eta, AJet), 0x0000000000000014);
				UProperty* NewProp_phi = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("phi"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(phi, AJet), 0x0000000000000014);
				UProperty* NewProp_coneR = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("coneR"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(coneR, AJet), 0x0000000000000014);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Jet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Jet.h"));
				MetaData->SetValue(NewProp_energy, TEXT("Category"), TEXT("Jet Parameters"));
				MetaData->SetValue(NewProp_energy, TEXT("ModuleRelativePath"), TEXT("Jet.h"));
				MetaData->SetValue(NewProp_eta, TEXT("Category"), TEXT("Jet Parameters"));
				MetaData->SetValue(NewProp_eta, TEXT("ModuleRelativePath"), TEXT("Jet.h"));
				MetaData->SetValue(NewProp_phi, TEXT("Category"), TEXT("Jet Parameters"));
				MetaData->SetValue(NewProp_phi, TEXT("ModuleRelativePath"), TEXT("Jet.h"));
				MetaData->SetValue(NewProp_coneR, TEXT("Category"), TEXT("Jet Parameters"));
				MetaData->SetValue(NewProp_coneR, TEXT("ModuleRelativePath"), TEXT("Jet.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJet(Z_Construct_UClass_AJet, TEXT("AJet"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJet);
	UFunction* Z_Construct_UFunction_UReporter_StartWork()
	{
		struct Reporter_eventStartWork_Parms
		{
			FString js;
		};
		UObject* Outer=Z_Construct_UClass_UReporter();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StartWork"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(Reporter_eventStartWork_Parms));
			UProperty* NewProp_js = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("js"), RF_Public|RF_Transient|RF_Native) UStrProperty(CPP_PROPERTY_BASE(js, Reporter_eventStartWork_Parms), 0x0000000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Report On"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Reporter.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UReporter_StopWork()
	{
		UObject* Outer=Z_Construct_UClass_UReporter();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StopWork"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Report On"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Reporter.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UReporter_NoRegister()
	{
		return UReporter::StaticClass();
	}
	UClass* Z_Construct_UClass_UReporter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage_ATLASrift();
			OuterClass = UReporter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;

				OuterClass->LinkChild(Z_Construct_UFunction_UReporter_StartWork());
				OuterClass->LinkChild(Z_Construct_UFunction_UReporter_StopWork());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_TargetHost = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TargetHost"), RF_Public|RF_Transient|RF_Native) UStrProperty(CPP_PROPERTY_BASE(TargetHost, UReporter), 0x0000000000010001);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_UReporter_StartWork()); // 2326253515
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_UReporter_StopWork()); // 2359642398
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("ComponentReplication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Reporter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Reporter.h"));
				MetaData->SetValue(NewProp_TargetHost, TEXT("Category"), TEXT("ReporterSettings"));
				MetaData->SetValue(NewProp_TargetHost, TEXT("ModuleRelativePath"), TEXT("Reporter.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UReporter(Z_Construct_UClass_UReporter, TEXT("UReporter"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReporter);
	UPackage* Z_Construct_UPackage_ATLASrift()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/ATLASrift")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x3402C428;
			Guid.B = 0x8A3621A5;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
