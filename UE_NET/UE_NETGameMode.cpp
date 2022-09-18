// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_NETGameMode.h"
#include "UE_NETCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_NETGameMode::AUE_NETGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
