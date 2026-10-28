// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class PANLINGGUYU_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	AWeapon();
	void Equip(USceneComponent* InParent, FName InSocketName, AActor* NewOwner, APawn* NewInstigator);

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

	TArray<AActor*> IgnoreActors;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void BoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon Propertise")
	class UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnywhere, Category = "Weapon Propertise")
	FVector BoxTraceExtent = FVector(5.f);

	UPROPERTY(EditAnywhere, Category = "Weapon Propertise")
	bool bShowBoxDebug = false;

	UPROPERTY(EditAnywhere, Category = "Weapon Propertise")
	float Damage = 20.f;
};