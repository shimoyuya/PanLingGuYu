// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/CharacterAnimInstanceBase.h"
#include "Characters/CharacterTypes.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PANLINGGUYU_API UPlayerAnimInstance : public UCharacterAnimInstanceBase
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class APlayerCharacter* PlayerCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	EActionState CharacterActionState;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	ECharacterState CharacterState;
};
