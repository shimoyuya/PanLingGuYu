// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateCombat.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PANLINGGUYU_API UBTService_UpdateCombat : public UBTService_BlackboardBase
{
	GENERATED_BODY()
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	FBlackboardKeySelector DistanceToTargetKey;
};
