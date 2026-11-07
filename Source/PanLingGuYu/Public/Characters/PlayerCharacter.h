// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Characters/CharacterTypes.h"
#include "Interfaces/InteractionInterface.h"
#include "PlayerCharacter.generated.h"

class UAnimMontage;
class AItem;
class AWeapon;

UCLASS()
class PANLINGGUYU_API APlayerCharacter : public ABaseCharacter,public IInteractionInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;

	virtual void Attack() override;
	void Dodge();
	void Interact();

	virtual void SetOverlapItem(AItem* Item) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState CharacterActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	ECharacterState CharacterState = ECharacterState::ECS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
	AItem* CurrentOverlapItem = nullptr;

public:
	FORCEINLINE EActionState GetCharacterActionState() const { return CharacterActionState; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
