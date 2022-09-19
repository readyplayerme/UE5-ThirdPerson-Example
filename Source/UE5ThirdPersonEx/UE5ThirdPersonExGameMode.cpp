// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5ThirdPersonExGameMode.h"
#include "UE5ThirdPersonExCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5ThirdPersonExGameMode::AUE5ThirdPersonExGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
