// Fill out your copyright notice in the Description page of Project Settings.


#include "ShrineInteractable.h"

// Sets default values
AShrineInteractable::AShrineInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*_RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	RootComponent=_RootComponent;

	ShrineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shrine mesh"));
	ShrineMesh->SetupAttachment(RootComponent);

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light bulb"));
	Light->SetupAttachment(RootComponent);*/
}

// Called when the game starts or when spawned
void AShrineInteractable::BeginPlay()
{
	//Super::BeginPlay();
	//Light->SetIntensity(0);
}

// Called every frame
void AShrineInteractable::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

//void AShrineInteractable::InteractWithMe()
//{
//	UE_LOG(LogTemp, Warning, TEXT("You have interacted with me!"));
//	Light->SetIntensity(10000);
//}


