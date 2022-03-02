// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MAJORPROJECT_InteractionInterface_generated_h
#error "InteractionInterface.generated.h already included, missing '#pragma once' in InteractionInterface.h"
#endif
#define MAJORPROJECT_InteractionInterface_generated_h

#define Major_Project_Source_MajorProject_InteractionInterface_h_13_SPARSE_DATA
#define Major_Project_Source_MajorProject_InteractionInterface_h_13_RPC_WRAPPERS
#define Major_Project_Source_MajorProject_InteractionInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define Major_Project_Source_MajorProject_InteractionInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MAJORPROJECT_API UInteractionInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractionInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MAJORPROJECT_API, UInteractionInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractionInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	MAJORPROJECT_API UInteractionInterface(UInteractionInterface&&); \
	MAJORPROJECT_API UInteractionInterface(const UInteractionInterface&); \
public:


#define Major_Project_Source_MajorProject_InteractionInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MAJORPROJECT_API UInteractionInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	MAJORPROJECT_API UInteractionInterface(UInteractionInterface&&); \
	MAJORPROJECT_API UInteractionInterface(const UInteractionInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MAJORPROJECT_API, UInteractionInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractionInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractionInterface)


#define Major_Project_Source_MajorProject_InteractionInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractionInterface(); \
	friend struct Z_Construct_UClass_UInteractionInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractionInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/MajorProject"), MAJORPROJECT_API) \
	DECLARE_SERIALIZER(UInteractionInterface)


#define Major_Project_Source_MajorProject_InteractionInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_GENERATED_UINTERFACE_BODY() \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Major_Project_Source_MajorProject_InteractionInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_GENERATED_UINTERFACE_BODY() \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Major_Project_Source_MajorProject_InteractionInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractionInterface() {} \
public: \
	typedef UInteractionInterface UClassType; \
	typedef IInteractionInterface ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define Major_Project_Source_MajorProject_InteractionInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IInteractionInterface() {} \
public: \
	typedef UInteractionInterface UClassType; \
	typedef IInteractionInterface ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define Major_Project_Source_MajorProject_InteractionInterface_h_10_PROLOG
#define Major_Project_Source_MajorProject_InteractionInterface_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_SPARSE_DATA \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_RPC_WRAPPERS \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Major_Project_Source_MajorProject_InteractionInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_SPARSE_DATA \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Major_Project_Source_MajorProject_InteractionInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MAJORPROJECT_API UClass* StaticClass<class UInteractionInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Major_Project_Source_MajorProject_InteractionInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
