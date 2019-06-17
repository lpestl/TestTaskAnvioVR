// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDevice.h"
#include "ThingBase.generated.h"

UCLASS()
class TESTTASKANVIOVR_API AThingBase : public AActor, public IIDevice
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThingBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

};


USTRUCT(BlueprintType)
struct TESTTASKANVIOVR_API FAvailableThingClass
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	TSubclassOf<AThingBase> Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	UTexture2D* Avatar;
};