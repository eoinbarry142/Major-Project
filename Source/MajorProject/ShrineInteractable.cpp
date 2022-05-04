// Fill out your copyright notice in the Description page of Project Settings.


#include "ShrineInteractable.h"
//#include "MajorProjectCharacter.h"
#include <Kismet/GameplayStatics.h>

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

	//MaterialOne = CreateDefaultSubobject<UMaterialInterface>("MaterialOne");
	//MaterialTwo = CreateDefaultSubobject<UMaterialInterface>("MaterialTwo");
}

// Called when the game starts or when spawned
void AShrineInteractable::BeginPlay()
{
	LevelName = GetWorld()->GetMapName();
	LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	//if (LevelName == "MainMenu")
	//	UGameplayStatics::PlaySoundAtLocation(GetWorld(), MainMenuSound, GetActorLocation(), 0.4f, 1.0f, 0.0f);
	Super::BeginPlay();
	Light->SetIntensity(0);
	activated = false;
	//InteractionWidget->SetOpacityFromTexture(1);
	InteractionWidget->SetVisibility(false);
	//ShrineMesh->SetMaterial(0, MaterialTwo);
	ShrineMesh->SetScalarParameterValueOnMaterials(TEXT("Runes"), 0.f);

	for (TObjectIterator<AMajorProjectCharacter> Itr; Itr; ++Itr)
	{
		if (Itr->IsA(AMajorProjectCharacter::StaticClass()))
		{
			AMajorProjectCharacter* actorClass = *Itr;
			actorClass->ResetShrineCount();
		}
	}
}

// Called every frame
void AShrineInteractable::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

void AShrineInteractable::InteractWithMe()
{

	if (activated == false) {
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Interacted"));
		//Light->SetIntensity(10000);
		activated = true;
		InteractionWidget->SetVisibility(false);

		//ShrineMesh->SetMaterial(0, MaterialOne);

		//Material = ShrineMesh->GetMaterial(0);
		//UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
		//ShrineMesh->SetMaterial(0, DynamicMaterial);
		//DynamicMaterial->SetScalarParameterValue(TEXT("Runes"), 1);

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), shrineActivateSound, GetActorLocation(), 0.4f, 1.0f, 0.0f);

		//Material = ShrineMesh->GetMaterial(0);
		//UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
		//ShrineMesh->SetMaterial(0, DynamicMaterial);

		//DynamicMaterial->SetScalarParameterValue(TEXT("Runes"), temp);
		//temp += 0.01f;
		//GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &AShrineInteractable::OnTimerEnd, 0.01f, false);
		OnTimerEnd();
		
		//GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle3, this, &AShrineInteractable::onTimerEnd, 1.f, false);
		//GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle4, this, &AShrineInteractable::onTimerEnd, 1.f, false);

		//ShrineMesh->SetScalarParameterValue(Runes, 1);

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

void AShrineInteractable::OnTimerEnd()
{
	ShrineMesh->SetScalarParameterValueOnMaterials(TEXT("Runes"), temp);
	temp += 0.01f;
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("YOU WIN"));

	if (temp < 1.0f)
		GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &AShrineInteractable::OnTimerEnd, 0.01f, false);

	LevelName = GetWorld()->GetMapName();
	LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	if (LevelName == "MainMenu" && temp > 0.98f)
		GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle2, this, &AShrineInteractable::NextLevel, 2.f, false);
}

void AShrineInteractable::NextLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Island"));
}