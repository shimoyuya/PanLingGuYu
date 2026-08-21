// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PLGYPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Characters/PlayerCharacter.h"

void APLGYPlayerController::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
	}	
}

void APLGYPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(LookAxisVector.X);
		ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void APLGYPlayerController::Jump()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (PlayerCharacter)
	{
		PlayerCharacter->Jump();
	}
}

void APLGYPlayerController::StopJump()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (PlayerCharacter)
	{
		PlayerCharacter->StopJumping();
	}
}

void APLGYPlayerController::Attack()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (PlayerCharacter)
	{
		PlayerCharacter->Attack();
	}
}

void APLGYPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerContext) 
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(PlayerContext, 0);
		}
	}
}

void APLGYPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	if (MoveAction) 
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APLGYPlayerController::Move);
	}
	if (LookAction) 
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APLGYPlayerController::Look);
	}
	if (JumpAction)
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APLGYPlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APLGYPlayerController::StopJump);
	}
	if (AttackAction)
	{
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &APLGYPlayerController::Attack);
	}
}
