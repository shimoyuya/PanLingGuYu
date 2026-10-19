// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Gear.generated.h"

/**
 * 
 */
UCLASS()
class PANLINGGUYU_API AGear : public AItem
{
	GENERATED_BODY()
	
public:
	AGear();
	void Equip(USceneComponent* InParent, FName InSocketName);
protected:

};
