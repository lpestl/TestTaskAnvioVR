// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlotsWidgetBase.h"
#include "GameFramework/PlayerController.h"
#include "TestTaskPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASKANVIOVR_API ATestTaskPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATestTaskPlayerController();

	// Override BeginPlay()
	virtual void BeginPlay() override;

	UFUNCTION()
	APawn* SpawnPlayerPawn(TSubclassOf<APawn> SpawnClass, AActor* PawnStartPoint);
	
	UFUNCTION()
	void OnInventoryCall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	bool bInventoryOpened;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	TSubclassOf<class USlotsWidgetBase> wInventory;

	USlotsWidgetBase* Inventory;
};
