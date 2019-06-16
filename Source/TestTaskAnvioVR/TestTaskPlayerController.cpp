// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTaskPlayerController.h"
#include "Engine/World.h"

ATestTaskPlayerController::ATestTaskPlayerController()
{

}

APawn* ATestTaskPlayerController::SpawnPlayerPawn(TSubclassOf<APawn> SpawnClass, AActor* PawnStartPoint)
{
	FTransform transform = PawnStartPoint->GetActorTransform();
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	APawn* charapter = GetWorld()->SpawnActor<APawn>(SpawnClass, transform, SpawnInfo);

	Possess(charapter);

	return charapter;
}
