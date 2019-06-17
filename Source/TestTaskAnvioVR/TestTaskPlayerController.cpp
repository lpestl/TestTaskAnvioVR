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
		if (IsLocalPlayerController()) 
		{
			// Create the widget and store it.
			Inventory = CreateWidget<USlotsWidgetBase>(this, wInventory);
			Inventory->AddToViewport();
			Inventory->SetVisibility(ESlateVisibility::Collapsed);
		}
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
	if (IsLocalPlayerController()) {
		if (Inventory) {
			if (bInventoryOpened)
			{
				//Inventory->RemoveFromViewport();
				Inventory->SetVisibility(ESlateVisibility::Collapsed);

				bShowMouseCursor = false;
				bInventoryOpened = false;
			}
			else
			{
				//Inventory->AddToViewport();
				Inventory->SetVisibility(ESlateVisibility::Visible);

				bShowMouseCursor = true;
				bInventoryOpened = true;
			}
		}
	}
}
