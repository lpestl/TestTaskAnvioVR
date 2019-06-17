// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SlotComponent.h"
#include "UserWidget.h"
#include "TestTaskCharacter.generated.h"

UCLASS(config = Game)
class TESTTASKANVIOVR_API ATestTaskCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY()
	TArray<FName> Sockets;

	UPROPERTY()
	TArray<AActor*> AttachedActors;

public:
	ATestTaskCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Task")
	class USlotComponent* SlotsComponent;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UFUNCTION(BlueprintCallable, Category = "Test Task")
	void UnEquip(FName SocketName);

	UFUNCTION(BlueprintCallable, Category = "Test Task")
	void Equip(FName SocketName, UClass* ThingClass);
	
	UFUNCTION(Server, Reliable, WithValidation)
	void EquipOnServer(FName SocketName, UClass* ThingClass);
	void EquipOnServer_Implementation(FName SocketName, UClass* ThingClass);
	bool EquipOnServer_Validate(FName SocketName, UClass* ThingClass);
	
	UFUNCTION(Server, Reliable, WithValidation)
	void UnEquipOnServer(FName SocketName);
	void UnEquipOnServer_Implementation(FName SocketName);
	bool UnEquipOnServer_Validate(FName SocketName);

protected:
	void OnInventoryCall();

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};
