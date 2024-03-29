// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ThingBase.h"
#include "SlotComponent.generated.h"


USTRUCT(BlueprintType)
struct TESTTASKANVIOVR_API FSlot
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	TArray<FAvailableThingClass> AvailableClasses;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASKANVIOVR_API USlotComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlotComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	TArray<FSlot> Slots;
};
