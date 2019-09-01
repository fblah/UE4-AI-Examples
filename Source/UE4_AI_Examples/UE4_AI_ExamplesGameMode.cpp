// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4_AI_ExamplesGameMode.h"
#include "UE4_AI_ExamplesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4_AI_ExamplesGameMode::AUE4_AI_ExamplesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
