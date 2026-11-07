// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_Attack.h"
#include "AIController.h"
#include "Characters/EnemyCharacter.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	AAIController* AIController =  OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;

	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(AIController->GetPawn());
	if (Enemy)
	{
		Enemy->Attack();
		GEngine->AddOnScreenDebugMessage(3, 1.f, FColor::Black, FString("Attack"));
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
