// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTaskGameModeBase.h"
#include "ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "TestTaskPlayerController.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"

ATestTaskGameModeBase::ATestTaskGameModeBase()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TestTask/Player/BP_RedPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
	static ConstructorHelpers::FClassFinder<ATestTaskCharacter> RedPlayerPawnBPClass(TEXT("/Game/TestTask/Player/BP_RedPlayer"));
	static ConstructorHelpers::FClassFinder<ATestTaskCharacter> GreenPlayerPawnBPClass(TEXT("/Game/TestTask/Player/BP_GreenPlayer"));
	static ConstructorHelpers::FClassFinder<ATestTaskCharacter> BluePlayerPawnBPClass(TEXT("/Game/TestTask/Player/BP_BluePlayer"));

	PlayerTypes.Add(RedPlayerPawnBPClass.Class);
	PlayerTypes.Add(GreenPlayerPawnBPClass.Class);
	PlayerTypes.Add(BluePlayerPawnBPClass.Class);

	CountPlayerTypes.Add(0);
	CountPlayerTypes.Add(0);
	CountPlayerTypes.Add(0);

	PlayerControllerClass = ATestTaskPlayerController::StaticClass();
}

APawn* ATestTaskGameModeBase::SpawnDefaultPawnFor_Implementation(AController* Controller, AActor* Actor)
{
	int32 n_min = 0;
	for (int32 i = 0; i < CountPlayerTypes.Num(); ++i)
	{
		if (CountPlayerTypes[i] < CountPlayerTypes[n_min])
		{
			n_min = i;
		}
	}
	CountPlayerTypes[n_min]++;

	AActor* ChoisedPlayerStart = nullptr;
	for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		APlayerStart* currStart = *ActorItr;
		if (!currStart->ActorHasTag(FName("Taken")))
		{
			ChoisedPlayerStart = currStart;
			currStart->Tags.Add(FName("Taken"));
			break;
		}
	}
	
	ATestTaskPlayerController* MyController = Cast<ATestTaskPlayerController>(Controller);
	if ((MyController) && (ChoisedPlayerStart))
	{
		return MyController->SpawnPlayerPawn(PlayerTypes[n_min], ChoisedPlayerStart);
	}

	return nullptr;
}

