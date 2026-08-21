// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}