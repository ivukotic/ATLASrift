// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBPUniqueNetId;
class APlayerController;
#ifdef ADVANCEDSESSIONS_AdvancedExternalUILibrary_generated_h
#error "AdvancedExternalUILibrary.generated.h already included, missing '#pragma once' in AdvancedExternalUILibrary.h"
#endif
#define ADVANCEDSESSIONS_AdvancedExternalUILibrary_generated_h

#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execShowAccountUpgradeUI) \
	{ \
		P_GET_STRUCT(FBPUniqueNetId,Z_Param_PlayerRequestingAccountUpgradeUI); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowAccountUpgradeUI(Z_Param_PlayerRequestingAccountUpgradeUI,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowProfileUI) \
	{ \
		P_GET_STRUCT(FBPUniqueNetId,Z_Param_PlayerViewingProfile); \
		P_GET_STRUCT(FBPUniqueNetId,Z_Param_PlayerToViewProfileOf); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowProfileUI(Z_Param_PlayerViewingProfile,Z_Param_PlayerToViewProfileOf,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowWebURLUI) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_URLToShow); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowWebURLUI(Z_Param_URLToShow,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowLeaderBoardUI) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_LeaderboardName); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowLeaderBoardUI(Z_Param_LeaderboardName,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowInviteUI) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowInviteUI(Z_Param_PlayerController,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowFriendsUI) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowFriendsUI(Z_Param_PlayerController,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	}


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execShowAccountUpgradeUI) \
	{ \
		P_GET_STRUCT(FBPUniqueNetId,Z_Param_PlayerRequestingAccountUpgradeUI); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowAccountUpgradeUI(Z_Param_PlayerRequestingAccountUpgradeUI,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowProfileUI) \
	{ \
		P_GET_STRUCT(FBPUniqueNetId,Z_Param_PlayerViewingProfile); \
		P_GET_STRUCT(FBPUniqueNetId,Z_Param_PlayerToViewProfileOf); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowProfileUI(Z_Param_PlayerViewingProfile,Z_Param_PlayerToViewProfileOf,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowWebURLUI) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_URLToShow); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowWebURLUI(Z_Param_URLToShow,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowLeaderBoardUI) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_LeaderboardName); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowLeaderBoardUI(Z_Param_LeaderboardName,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowInviteUI) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowInviteUI(Z_Param_PlayerController,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	} \
 \
	DECLARE_FUNCTION(execShowFriendsUI) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_Result); \
		P_FINISH; \
		UAdvancedExternalUILibrary::ShowFriendsUI(Z_Param_PlayerController,(TEnumAsByte<EBlueprintResultSwitch::Type>&)(Z_Param_Out_Result)); \
	}


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUAdvancedExternalUILibrary(); \
	friend ADVANCEDSESSIONS_API class UClass* Z_Construct_UClass_UAdvancedExternalUILibrary(); \
	public: \
	DECLARE_CLASS(UAdvancedExternalUILibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, AdvancedSessions, NO_API) \
	DECLARE_SERIALIZER(UAdvancedExternalUILibrary) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UAdvancedExternalUILibrary*>(this); }


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_INCLASS \
	private: \
	static void StaticRegisterNativesUAdvancedExternalUILibrary(); \
	friend ADVANCEDSESSIONS_API class UClass* Z_Construct_UClass_UAdvancedExternalUILibrary(); \
	public: \
	DECLARE_CLASS(UAdvancedExternalUILibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, AdvancedSessions, NO_API) \
	DECLARE_SERIALIZER(UAdvancedExternalUILibrary) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UAdvancedExternalUILibrary*>(this); }


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdvancedExternalUILibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdvancedExternalUILibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdvancedExternalUILibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdvancedExternalUILibrary); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UAdvancedExternalUILibrary(const UAdvancedExternalUILibrary& InCopy); \
public:


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdvancedExternalUILibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UAdvancedExternalUILibrary(const UAdvancedExternalUILibrary& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdvancedExternalUILibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdvancedExternalUILibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdvancedExternalUILibrary)


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_24_PROLOG
#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_RPC_WRAPPERS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_INCLASS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_INCLASS_NO_PURE_DECLS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_AdvancedExternalUILibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
