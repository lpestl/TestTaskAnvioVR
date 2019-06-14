// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTaskGameModeBase.h"
#include "ConstructorHelpers.h"

ATestTaskGameModeBase::ATestTaskGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TestTask/Player/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
