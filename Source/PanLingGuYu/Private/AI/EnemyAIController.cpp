// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyAIController::AEnemyAIController()
{
	EnemyAIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerceptionComp");
	SetPerceptionComponent(*EnemyAIPerceptionComponent);
	
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    SightConfig->SightRadius = 1500.0f;
    SightConfig->LoseSightRadius = 1800.0f;
    SightConfig->PeripheralVisionAngleDegrees = 70.0f;
    SightConfig->SetMaxAge(3.0f);

    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

    EnemyAIPerceptionComponent->ConfigureSense(*SightConfig);
    EnemyAIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    EnemyAIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::TargetPerceptionUpdated);
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(InPawn);
    if (Enemy && Enemy->GetBehaviorTree())
    {
        RunBehaviorTree(Enemy->GetBehaviorTree());
    }
}

void AEnemyAIController::TargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    APlayerCharacter* SensedCharacter = Cast<APlayerCharacter>(Actor);
    UBlackboardComponent* BlackBoard = GetBlackboardComponent();
    if (!SensedCharacter || !BlackBoard) return;

    if (Stimulus.WasSuccessfullySensed())
    {
        BlackBoard->SetValueAsObject(FName("TargetActor"), SensedCharacter);
    }
    else
    {
        BlackBoard->ClearValue(FName("TargetActor"));
    }
}
