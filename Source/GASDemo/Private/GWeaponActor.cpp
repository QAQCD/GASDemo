// Fill out your copyright notice in the Description page of Project Settings.


#include "GWeaponActor.h"


#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

#include "GCharacter.h"



// Sets default values
AGWeaponActor::AGWeaponActor()
{

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(SphereComp);

	WeaponComp = CreateDefaultSubobject<UCapsuleComponent>("WeaponComp");
	WeaponComp->SetupAttachment(SphereComp);
	
}

// Called when the game starts or when spawned
void AGWeaponActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

