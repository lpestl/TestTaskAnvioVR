// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TestTaskAnvioVRGameMode.h"
#include "TestTaskAnvioVRCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestTaskAnvioVRGameMode::ATestTaskAnvioVRGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
