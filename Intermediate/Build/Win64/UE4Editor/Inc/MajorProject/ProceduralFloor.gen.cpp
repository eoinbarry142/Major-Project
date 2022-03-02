// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MajorProject/ProceduralFloor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralFloor() {}
// Cross Module References
	MAJORPROJECT_API UClass* Z_Construct_UClass_AProceduralFloor_NoRegister();
	MAJORPROJECT_API UClass* Z_Construct_UClass_AProceduralFloor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MajorProject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void AProceduralFloor::StaticRegisterNativesAProceduralFloor()
	{
	}
	UClass* Z_Construct_UClass_AProceduralFloor_NoRegister()
	{
		return AProceduralFloor::StaticClass();
	}
	struct Z_Construct_UClass_AProceduralFloor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Floor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Floor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShrineClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ShrineClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProceduralFloor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MajorProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProceduralFloor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProceduralFloor.h" },
		{ "ModuleRelativePath", "ProceduralFloor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProceduralFloor_Statics::NewProp_Floor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Room" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProceduralFloor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProceduralFloor_Statics::NewProp_Floor = { "Floor", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProceduralFloor, Floor), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProceduralFloor_Statics::NewProp_Floor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProceduralFloor_Statics::NewProp_Floor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProceduralFloor_Statics::NewProp_ShrineClass_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Room" },
		{ "ModuleRelativePath", "ProceduralFloor.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AProceduralFloor_Statics::NewProp_ShrineClass = { "ShrineClass", nullptr, (EPropertyFlags)0x0044000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProceduralFloor, ShrineClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AProceduralFloor_Statics::NewProp_ShrineClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProceduralFloor_Statics::NewProp_ShrineClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProceduralFloor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProceduralFloor_Statics::NewProp_Floor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProceduralFloor_Statics::NewProp_ShrineClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProceduralFloor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProceduralFloor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProceduralFloor_Statics::ClassParams = {
		&AProceduralFloor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AProceduralFloor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AProceduralFloor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProceduralFloor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProceduralFloor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProceduralFloor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProceduralFloor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProceduralFloor, 2843842420);
	template<> MAJORPROJECT_API UClass* StaticClass<AProceduralFloor>()
	{
		return AProceduralFloor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProceduralFloor(Z_Construct_UClass_AProceduralFloor, &AProceduralFloor::StaticClass, TEXT("/Script/MajorProject"), TEXT("AProceduralFloor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProceduralFloor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
