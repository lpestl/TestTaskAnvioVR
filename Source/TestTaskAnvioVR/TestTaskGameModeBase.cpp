// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTaskGameModeBase.h"
#include "ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

ATestTaskGameModeBase::ATestTaskGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TestTask/Player/BP_RedPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

//AActor* ATestTaskGameModeBase::ChoosePlayerStart_Implementation(AController*)
//{
//	TArray<AActor*> PlayerStartList;
//	UGameplayStatics::GetAllActorsOfClass(this, TSubclassOf<APlayerStart>(), PlayerStartList);
//
//}
