// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTaskPlayerController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"

ATestTaskPlayerController::ATestTaskPlayerController()
{
	bInventoryOpened = false;
}

void ATestTaskPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (wInventory) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		Inventory = CreateWidget<USlotsWidgetBase>(this, wInventory);
	}
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

void ATestTaskPlayerController::OnInventoryCall()
{
	if (Inventory) {
		if (bInventoryOpened)
		{
			Inventory->RemoveFromViewport();

			bInventoryOpened = false;
		}
		else
		{
			Inventory->AddToViewport();

			bShowMouseCursor = true;
			bInventoryOpened = true;
		}
	}
}
