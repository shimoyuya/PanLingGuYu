// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_UpdateCombat.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/EnemyCharacter.h"
#include "AIController.h"

void UBTService_UpdateCombat::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* AIOwner = OwnerComp.GetAIOwner();
	if (!AIOwner) return;
	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(AIOwner->GetPawn());

	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	APlayerCharacter* Target = Cast<APlayerCharacter>(BlackBoard->GetValueAsObject(FName("TargetActor")));
	if (Target && Enemy)
	{
		float Distance = Enemy->GetDistanceTo(Target);
		BlackBoard->SetValueAsFloat(DistanceToTargetKey.SelectedKeyName, Distance);
	}
}