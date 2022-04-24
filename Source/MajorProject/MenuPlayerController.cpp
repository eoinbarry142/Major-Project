// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController()
{

}

/*void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
	}
}*/

//void AMenuPlayerController::OpenMenu()
//{
//	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
//	{
//		MenuHUD->ShowPauseMenu();
//	}
//}

//void AMenuPlayerController::IslandLevel()
//{
//	FString current = GetWorld()->GetMapName();
//	UGameplayStatics::OpenLevel(GetWorld(), FName("Island"));
//}
//
//void AMenuPlayerController::FinalLevel()
//{
//	FString current = GetWorld()->GetMapName();
//	UGameplayStatics::OpenLevel(GetWorld(), FName("NewMap"));
//}
