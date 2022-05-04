// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatClass.h"
//#include "MajorProjectCharacter.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ABoatClass::ABoatClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	RootComponent = _RootComponent;

	ShrineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shrine mesh"));
	ShrineMesh->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Widget"));
	InteractionWidget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABoatClass::BeginPlay()
{
	Super::BeginPlay();
	activated = false;
	InteractionWidget->SetVisibility(false);
}

// Called every frame
void ABoatClass::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
}

void ABoatClass::InteractWithMe()
{
	if (activated == false && isReady == true) {
		//Turn off widget
		InteractionWidget->SetVisibility(false);

		//Get level name
		LevelName = GetWorld()->GetMapName();
		LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

		//Open new map depending on what map player is currently in
		if (LevelName == "Island")
			UGameplayStatics::OpenLevel(GetWorld(), FName("WinMenu"));
		else
			UGameplayStatics::OpenLevel(GetWorld(), FName("WinMenu2"));

		//Make sure can't be activated again
		activated = true;
	}
}

void ABoatClass::ShowInteractionWidget()
{
	if (activated == false && isReady == true) {
		InteractionWidget->SetVisibility(true);
	}
}

void ABoatClass::HideInteractionWidget()
{
	InteractionWidget->SetVisibility(false);
}

void ABoatClass::Ready() {
	isReady = true;

	if (wCrossHairWidget) {
		auto name = FName(TEXT("CH"));
		CrossHairWidget = CreateWidget<UUserWidget>(GetGameInstance(), wCrossHairWidget, name);
		if (CrossHairWidget)
		{
			CrossHairWidget->AddToViewport();
		}
	}

	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Yellow, TEXT("ready"));
}