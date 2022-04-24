// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SMainMenuWidget.h"
#include "SPauseMenuWidget.h"
#include "SWinMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	//LevelName = GetWorld()->GetMapName();
	//LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	//if(LevelName == "MainMenu")
		//ShowMenu();
	//if (LevelName == "WinMenu")
		//ShowWinMenu();
}

//void AMenuHUD::ShowMenu()
//{
//	if (GEngine && GEngine->GameViewport)
//	{
//		MenuWidget = SNew(SMainMenuWidget).OwningHUD(this);
//		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
//
//		if (PlayerOwner)
//		{
//			PlayerOwner->bShowMouseCursor = true;
//			PlayerOwner->SetInputMode(FInputModeUIOnly());
//		}
//	}
//}

//void AMenuHUD::ShowPauseMenu()
//{
//	if (GEngine && GEngine->GameViewport)
//	{
//		LevelName = GetWorld()->GetMapName();
//		LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
//		if (LevelName == "Island")
//		{
//			PauseMenuWidget = SNew(SPauseMenuWidget).OwningHUD(this);
//			GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(PauseMenuWidgetContainer, SWeakWidget).PossiblyNullContent(PauseMenuWidget.ToSharedRef()));
//
//			if (PlayerOwner)
//			{
//				PlayerOwner->bShowMouseCursor = true;
//				PlayerOwner->SetInputMode(FInputModeUIOnly());
//			}
//		}
//	}
//}

//void AMenuHUD::ShowWinMenu()
//{
//	if (GEngine && GEngine->GameViewport)
//	{
//		WinMenuWidget = SNew(SWinMenuWidget).OwningHUD(this);
//		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WinMenuWidgetContainer, SWeakWidget).PossiblyNullContent(WinMenuWidget.ToSharedRef()));
//
//		if (PlayerOwner)
//		{
//			PlayerOwner->bShowMouseCursor = true;
//			PlayerOwner->SetInputMode(FInputModeUIOnly());
//		}
//	}
//}
//
//void AMenuHUD::RemoveMenu()
//{
//	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
//	{
//		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
//
//		if (PlayerOwner)
//		{
//			PlayerOwner->bShowMouseCursor = false;
//			PlayerOwner->SetInputMode(FInputModeGameOnly());
//		}
//	}
//
//}
//
//void AMenuHUD::RemovePauseMenu()
//{
//	if (GEngine && GEngine->GameViewport && PauseMenuWidgetContainer.IsValid())
//	{
//		GEngine->GameViewport->RemoveViewportWidgetContent(PauseMenuWidgetContainer.ToSharedRef());
//
//		if (PlayerOwner)
//		{
//			PlayerOwner->bShowMouseCursor = false;
//			PlayerOwner->SetInputMode(FInputModeGameOnly());
//		}
//	}
//
//}
//
//void AMenuHUD::RemoveWinMenu()
//{
//	if (GEngine && GEngine->GameViewport && WinMenuWidgetContainer.IsValid())
//	{
//		GEngine->GameViewport->RemoveViewportWidgetContent(WinMenuWidgetContainer.ToSharedRef());
//
//		if (PlayerOwner)
//		{
//			PlayerOwner->bShowMouseCursor = false;
//			PlayerOwner->SetInputMode(FInputModeGameOnly());
//		}
//	}
//
//}
