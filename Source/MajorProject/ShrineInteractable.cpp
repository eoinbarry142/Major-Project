// Fill out your copyright notice in the Description page of Project Settings.


#include "ShrineInteractable.h"
//#include "MajorProjectCharacter.h"

// Sets default values
AShrineInteractable::AShrineInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	RootComponent = _RootComponent;

	ShrineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shrine mesh"));
	ShrineMesh->SetupAttachment(RootComponent);

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light bulb"));
	Light->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Widget"));
	InteractionWidget->SetupAttachment(RootComponent);
	//InteractionWidget->SetVisibility(false);
}

// Called when the game starts or when spawned
void AShrineInteractable::BeginPlay()
{
	Super::BeginPlay();
	Light->SetIntensity(0);
	activated = false;
	//InteractionWidget->SetOpacityFromTexture(1);
	InteractionWidget->SetVisibility(false);
}

// Called every frame
void AShrineInteractable::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

void AShrineInteractable::InteractWithMe()
{
	if (activated == false) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Interacted"));
		Light->SetIntensity(10000);
		activated = true;
		InteractionWidget->SetVisibility(false);
		for (TObjectIterator<AMajorProjectCharacter> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(AMajorProjectCharacter::StaticClass()))
			{
				AMajorProjectCharacter* actorClass = *Itr;
				actorClass->ShrineCountIncrement();
			}
		}
	}


}

//int global_variable = 0;

//int increment(void) { return global_variable++; }





void AShrineInteractable::ShowInteractionWidget()
{
	//InteractionWidget->SetOpacityFromTexture(0);
	//InteractionWidget->SetActive(true);
	if (activated == false) {
		InteractionWidget->SetVisibility(true);
	}
}

void AShrineInteractable::HideInteractionWidget()
{
	//InteractionWidget->SetOpacityFromTexture(1);
	//InteractionWidget->SetActive(true);
	InteractionWidget->SetVisibility(false);
}




