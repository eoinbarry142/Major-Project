// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAJORPROJECT_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:

	TSharedPtr<class SMainMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;

	TSharedPtr<class SPauseMenuWidget> PauseMenuWidget;
	TSharedPtr<class SWidget> PauseMenuWidgetContainer;

	virtual void BeginPlay() override;

	FString LevelName;

public:

	void ShowMenu();
	void ShowPauseMenu();
	void RemoveMenu();
	void RemovePauseMenu();
	
};
