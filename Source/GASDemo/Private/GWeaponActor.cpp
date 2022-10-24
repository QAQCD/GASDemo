// Fill out your copyright notice in the Description page of Project Settings.


#include "GWeaponActor.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GCharacter.h"



// Sets default values
AGWeaponActor::AGWeaponActor()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void AGWeaponActor::BeginPlay()
{

}

// Called every frame
void AGWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGWeaponActor::Equip(AGCharacter* AOwner)
{
	if (AOwner)
	{
		//将冲突响应设置为通道:全部忽略
		Mesh->SetCollisionResponseToChannels(ECR_Ignore);
		Mesh->SetSimulatePhysics(false);

	}
}

