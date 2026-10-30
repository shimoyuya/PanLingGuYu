// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "Components/AttributeComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AttributeComponent = CreateDefaultSubobject<UAttributeComponent>("AttributeComponent");
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter)
{
	if (AttributeComponent && AttributeComponent->IsAlive())
	{
		FName SectionName("FromBack");
		float Theta = Directional(Hitter->GetActorLocation());

		if (Theta >= -90.f && Theta < 90.f)
		{
			SectionName = FName("FromFront");
		}
		PlayMontageSection(HitReactMontage, SectionName);
	}
	else Die();
	
}

void ABaseCharacter::Die_Implementation()
{
	PlayMontageSection(DeathMontage, FName("Death"));
}

float ABaseCharacter::Directional(const FVector& ImpactPoint)
{
	// 获取水平面上的方向向量
	const FVector Forward = GetActorForwardVector();
	const FVector ImpactLowered(ImpactPoint.X, ImpactPoint.Y, GetActorLocation().Z);
	const FVector ToImpactPoint = (ImpactLowered - GetActorLocation()).GetSafeNormal();

	// 使用点乘计算夹角大小 (0 到 180 度)
	const double CosTheta = FVector::DotProduct(Forward, ToImpactPoint);
	double Theta = FMath::Acos(CosTheta);
	Theta = FMath::RadiansToDegrees(Theta);
	// 使用叉乘判断受击方向是偏左还是偏右
	const FVector CrossProduct = FVector::CrossProduct(Forward, ToImpactPoint);
	if (CrossProduct.Z < 0)
	{
		Theta *= -1.0f;
	}

	return Theta;
}

void ABaseCharacter::PlayMontageSection(UAnimMontage* Montage, const FName& SectionName)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && Montage)
	{
		AnimInstance->Montage_Play(Montage);
		AnimInstance->Montage_JumpToSection(SectionName, Montage);
	}
}