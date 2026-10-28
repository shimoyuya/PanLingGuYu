// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/CharacterAnimInstanceBase.h"
#include "Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<ABaseCharacter>(TryGetPawnOwner());

	if (Character)
	{
		CharacterMovement = Character->GetCharacterMovement();
	}
}

void UCharacterAnimInstanceBase::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (CharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(CharacterMovement->Velocity);
		bIsFalling = CharacterMovement->IsFalling();
		EquippedWeapon = Character->GetEquippedWeapon();
	}
}