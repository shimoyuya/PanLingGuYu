// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapon.h"
#include "Components/SphereComponent.h"

AWeapon::AWeapon()
{

}

void AWeapon::Equip(USceneComponent* InParent, FName InSocketName)
{
	ItemMesh->AttachToComponent(InParent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), InSocketName);
	InteractionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
