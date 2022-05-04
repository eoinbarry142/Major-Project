// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Components/PointLightComponent.h"
#include "Components/WidgetComponent.h"
#include "MajorProjectCharacter.h"
#include <Kismet/GameplayStatics.h>
#include "Blueprint/UserWidget.h"

#include "BoatClass.generated.h"

UCLASS()
class MAJORPROJECT_API ABoatClass : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoatClass();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, category = "InteractWithMe")
		virtual void InteractWithMe() override;

	virtual void ShowInteractionWidget() override;
	virtual void HideInteractionWidget() override;

	void Ready();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wCrossHairWidget;

	UUserWidget* CrossHairWidget;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ShrineMesh;

	UPROPERTY(EditAnywhere)
		UWidgetComponent* InteractionWidget;

	bool activated;
	bool isReady = false;

	FString LevelName;
};
