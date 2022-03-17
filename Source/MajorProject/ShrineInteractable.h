// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Components/PointLightComponent.h"
#include "Components/WidgetComponent.h"
#include "MajorProjectCharacter.h"

#include "ShrineInteractable.generated.h"

UCLASS()
class MAJORPROJECT_API AShrineInteractable : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShrineInteractable();

	//extern int global_variable;

	//UFUNCTION()
	//void shrineCountIncrement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InteractWithMe() override;

	virtual void ShowInteractionWidget() override;
	virtual void HideInteractionWidget() override;

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ShrineMesh;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Light;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* InteractionWidget;

	bool activated;
};
