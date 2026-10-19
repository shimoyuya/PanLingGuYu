// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Items/Gear.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::Attack()
{
	if (CharacterActionState != EActionState::EAS_Unoccupied) return;

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance)
	{
		AnimInstance->Montage_Play(AttackMontage);
		AnimInstance->Montage_JumpToSection(FName("Attack1"),AttackMontage);
		CharacterActionState = EActionState::EAS_Attacking;
	}
}

void APlayerCharacter::Dodge()
{
	if (CharacterActionState != EActionState::EAS_Unoccupied) return;

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance)
	{
		AnimInstance->Montage_Play(DodgeMontage);
		CharacterActionState = EActionState::EAS_Dodge;
	}
}

void APlayerCharacter::Interact()
{
	if (!CurrentOverlapItem) { return; }

	AGear* Gear = Cast<AGear>(CurrentOverlapItem);
	if (Gear)
	{
		Gear->Equip(GetMesh(), FName("RightHandSocket"));
	}
}

void APlayerCharacter::SetOverlapItem(AItem* Item)
{
	CurrentOverlapItem = Item;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}