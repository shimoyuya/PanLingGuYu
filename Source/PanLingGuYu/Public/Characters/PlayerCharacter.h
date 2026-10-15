// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Characters/CharacterTypes.h"
#include "Interfaces/InteractionInterface.h"
#include "PlayerCharacter.generated.h"

class UAnimMontage;
class Item;

UCLASS()
class PANLINGGUYU_API APlayerCharacter : public ACharacter,public IInteractionInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;

	void Attack();
	void Dodge();

	virtual void SetOverlapItem(AItem* Item) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* DodgeMontage;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState CharacterActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
	AItem* CurrentOverlapItem = nullptr;

public:
	FORCEINLINE EActionState GetCharacterActionState() const { return CharacterActionState; }
	void SetCharacterActionState(EActionState ActionState) { CharacterActionState = ActionState; }
};
