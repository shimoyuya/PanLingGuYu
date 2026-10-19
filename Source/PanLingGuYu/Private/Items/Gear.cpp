// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Gear.h"
#include "Components/SphereComponent.h"

AGear::AGear()
{

}

void AGear::Equip(USceneComponent* InParent, FName InSocketName)
{
	ItemMesh->AttachToComponent(InParent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), InSocketName);
	InteractionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
