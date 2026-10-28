// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "BaseCharacter.generated.h"

class UAttributeComponent;
class AWeapon;

UCLASS()
class PANLINGGUYU_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;	
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* AttributeComponent;

	UPROPERTY(VisibleAnywhere)
	AWeapon* EquippedWeapon = nullptr;

private:

public:
	FORCEINLINE AWeapon* GetEquippedWeapon() const { return EquippedWeapon; }
};