// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestTaskCharacter.h"
#include "TestTaskGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASKANVIOVR_API ATestTaskGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestTaskGameModeBase();

	//UFUNCTION(Reliable, Server, WithValidation)
	APawn* SpawnDefaultPawnFor(AController* Controller, AActor* Actor);
	APawn* SpawnDefaultPawnFor_Implementation(AController* Controller, AActor* Actor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	TArray<TSubclassOf<ATestTaskCharacter>> PlayerTypes;
	TArray<int32> CountPlayerTypes;
};
