// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MajorProject/ShrineInteractable.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShrineInteractable() {}
// Cross Module References
	MAJORPROJECT_API UClass* Z_Construct_UClass_AShrineInteractable_NoRegister();
	MAJORPROJECT_API UClass* Z_Construct_UClass_AShrineInteractable();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MajorProject();
	MAJORPROJECT_API UClass* Z_Construct_UClass_UInteractionInterface_NoRegister();
// End Cross Module References
	void AShrineInteractable::StaticRegisterNativesAShrineInteractable()
	{
	}
	UClass* Z_Construct_UClass_AShrineInteractable_NoRegister()
	{
		return AShrineInteractable::StaticClass();
	}
	struct Z_Construct_UClass_AShrineInteractable_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShrineInteractable_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MajorProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShrineInteractable_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ShrineInteractable.h" },
		{ "ModuleRelativePath", "ShrineInteractable.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AShrineInteractable_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractionInterface_NoRegister, (int32)VTABLE_OFFSET(AShrineInteractable, IInteractionInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShrineInteractable_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShrineInteractable>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShrineInteractable_Statics::ClassParams = {
		&AShrineInteractable::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AShrineInteractable_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShrineInteractable_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShrineInteractable()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShrineInteractable_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShrineInteractable, 510494823);
	template<> MAJORPROJECT_API UClass* StaticClass<AShrineInteractable>()
	{
		return AShrineInteractable::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShrineInteractable(Z_Construct_UClass_AShrineInteractable, &AShrineInteractable::StaticClass, TEXT("/Script/MajorProject"), TEXT("AShrineInteractable"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShrineInteractable);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
