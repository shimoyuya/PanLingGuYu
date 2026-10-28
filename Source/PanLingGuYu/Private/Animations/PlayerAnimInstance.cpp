// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/PlayerAnimInstance.h"
#include "Characters/PlayerCharacter.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PlayerCharacter = Cast<APlayerCharacter>(Character);
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (CharacterMovement && PlayerCharacter)
	{
		CharacterActionState = PlayerCharacter->GetCharacterActionState();
		CharacterState = PlayerCharacter->GetCharacterState();
	}
}