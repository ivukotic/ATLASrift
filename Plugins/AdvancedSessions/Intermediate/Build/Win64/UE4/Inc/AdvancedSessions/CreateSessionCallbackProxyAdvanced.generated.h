// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FSessionPropertyKeyPair;
class APlayerController;
class UCreateSessionCallbackProxyAdvanced;
#ifdef ADVANCEDSESSIONS_CreateSessionCallbackProxyAdvanced_generated_h
#error "CreateSessionCallbackProxyAdvanced.generated.h already included, missing '#pragma once' in CreateSessionCallbackProxyAdvanced.h"
#endif
#define ADVANCEDSESSIONS_CreateSessionCallbackProxyAdvanced_generated_h

#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateAdvancedSession) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FSessionPropertyKeyPair,Z_Param_Out_ExtraSettings); \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PublicConnections); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PrivateConnections); \
		P_GET_UBOOL(Z_Param_bUseLAN); \
		P_GET_UBOOL(Z_Param_bAllowInvites); \
		P_GET_UBOOL(Z_Param_bIsDedicatedServer); \
		P_GET_UBOOL(Z_Param_bUsePresence); \
		P_GET_UBOOL(Z_Param_bAllowJoinViaPresence); \
		P_GET_UBOOL(Z_Param_bAllowJoinViaPresenceFriendsOnly); \
		P_GET_UBOOL(Z_Param_bAntiCheatProtected); \
		P_GET_UBOOL(Z_Param_bUsesStats); \
		P_GET_UBOOL(Z_Param_bShouldAdvertise); \
		P_FINISH; \
		*(UCreateSessionCallbackProxyAdvanced**)Z_Param__Result=UCreateSessionCallbackProxyAdvanced::CreateAdvancedSession(Z_Param_WorldContextObject,Z_Param_Out_ExtraSettings,Z_Param_PlayerController,Z_Param_PublicConnections,Z_Param_PrivateConnections,Z_Param_bUseLAN,Z_Param_bAllowInvites,Z_Param_bIsDedicatedServer,Z_Param_bUsePresence,Z_Param_bAllowJoinViaPresence,Z_Param_bAllowJoinViaPresenceFriendsOnly,Z_Param_bAntiCheatProtected,Z_Param_bUsesStats,Z_Param_bShouldAdvertise); \
	}


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateAdvancedSession) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FSessionPropertyKeyPair,Z_Param_Out_ExtraSettings); \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PublicConnections); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PrivateConnections); \
		P_GET_UBOOL(Z_Param_bUseLAN); \
		P_GET_UBOOL(Z_Param_bAllowInvites); \
		P_GET_UBOOL(Z_Param_bIsDedicatedServer); \
		P_GET_UBOOL(Z_Param_bUsePresence); \
		P_GET_UBOOL(Z_Param_bAllowJoinViaPresence); \
		P_GET_UBOOL(Z_Param_bAllowJoinViaPresenceFriendsOnly); \
		P_GET_UBOOL(Z_Param_bAntiCheatProtected); \
		P_GET_UBOOL(Z_Param_bUsesStats); \
		P_GET_UBOOL(Z_Param_bShouldAdvertise); \
		P_FINISH; \
		*(UCreateSessionCallbackProxyAdvanced**)Z_Param__Result=UCreateSessionCallbackProxyAdvanced::CreateAdvancedSession(Z_Param_WorldContextObject,Z_Param_Out_ExtraSettings,Z_Param_PlayerController,Z_Param_PublicConnections,Z_Param_PrivateConnections,Z_Param_bUseLAN,Z_Param_bAllowInvites,Z_Param_bIsDedicatedServer,Z_Param_bUsePresence,Z_Param_bAllowJoinViaPresence,Z_Param_bAllowJoinViaPresenceFriendsOnly,Z_Param_bAntiCheatProtected,Z_Param_bUsesStats,Z_Param_bShouldAdvertise); \
	}


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUCreateSessionCallbackProxyAdvanced(); \
	friend ADVANCEDSESSIONS_API class UClass* Z_Construct_UClass_UCreateSessionCallbackProxyAdvanced(); \
	public: \
	DECLARE_CLASS(UCreateSessionCallbackProxyAdvanced, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), 0, AdvancedSessions, ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UCreateSessionCallbackProxyAdvanced) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UCreateSessionCallbackProxyAdvanced*>(this); }


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesUCreateSessionCallbackProxyAdvanced(); \
	friend ADVANCEDSESSIONS_API class UClass* Z_Construct_UClass_UCreateSessionCallbackProxyAdvanced(); \
	public: \
	DECLARE_CLASS(UCreateSessionCallbackProxyAdvanced, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), 0, AdvancedSessions, ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UCreateSessionCallbackProxyAdvanced) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UCreateSessionCallbackProxyAdvanced*>(this); }


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UCreateSessionCallbackProxyAdvanced(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCreateSessionCallbackProxyAdvanced) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UCreateSessionCallbackProxyAdvanced); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCreateSessionCallbackProxyAdvanced); \
private: \
	/** Private copy-constructor, should never be used */ \
	ADVANCEDSESSIONS_API UCreateSessionCallbackProxyAdvanced(const UCreateSessionCallbackProxyAdvanced& InCopy); \
public:


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UCreateSessionCallbackProxyAdvanced(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	ADVANCEDSESSIONS_API UCreateSessionCallbackProxyAdvanced(const UCreateSessionCallbackProxyAdvanced& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UCreateSessionCallbackProxyAdvanced); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCreateSessionCallbackProxyAdvanced); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCreateSessionCallbackProxyAdvanced)


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_8_PROLOG
#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_INCLASS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_INCLASS_NO_PURE_DECLS \
	ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CreateSessionCallbackProxyAdvanced."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ATLASrift_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_CreateSessionCallbackProxyAdvanced_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
