// Copyright Epic Games, Inc. All Rights Reserved.

#include "MajorProjectGameMode.h"
#include "MajorProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMajorProjectGameMode::AMajorProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
