// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class PANLINGGUYU_API UCharacterAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class ABaseCharacter* Character;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class UCharacterMovementComponent* CharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class AWeapon* EquippedWeapon;
};
