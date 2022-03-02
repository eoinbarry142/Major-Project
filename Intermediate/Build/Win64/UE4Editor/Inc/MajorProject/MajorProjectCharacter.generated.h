// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MAJORPROJECT_MajorProjectCharacter_generated_h
#error "MajorProjectCharacter.generated.h already included, missing '#pragma once' in MajorProjectCharacter.h"
#endif
#define MAJORPROJECT_MajorProjectCharacter_generated_h

#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_SPARSE_DATA
#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_RPC_WRAPPERS
#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMajorProjectCharacter(); \
	friend struct Z_Construct_UClass_AMajorProjectCharacter_Statics; \
public: \
	DECLARE_CLASS(AMajorProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MajorProject"), NO_API) \
	DECLARE_SERIALIZER(AMajorProjectCharacter)


#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMajorProjectCharacter(); \
	friend struct Z_Construct_UClass_AMajorProjectCharacter_Statics; \
public: \
	DECLARE_CLASS(AMajorProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MajorProject"), NO_API) \
	DECLARE_SERIALIZER(AMajorProjectCharacter)


#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMajorProjectCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMajorProjectCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMajorProjectCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMajorProjectCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMajorProjectCharacter(AMajorProjectCharacter&&); \
	NO_API AMajorProjectCharacter(const AMajorProjectCharacter&); \
public:


#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMajorProjectCharacter(AMajorProjectCharacter&&); \
	NO_API AMajorProjectCharacter(const AMajorProjectCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMajorProjectCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMajorProjectCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMajorProjectCharacter)


#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AMajorProjectCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AMajorProjectCharacter, FollowCamera); }


#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_9_PROLOG
#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_SPARSE_DATA \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_RPC_WRAPPERS \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_INCLASS \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_SPARSE_DATA \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_INCLASS_NO_PURE_DECLS \
	Major_Project_Source_MajorProject_MajorProjectCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MAJORPROJECT_API UClass* StaticClass<class AMajorProjectCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Major_Project_Source_MajorProject_MajorProjectCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
