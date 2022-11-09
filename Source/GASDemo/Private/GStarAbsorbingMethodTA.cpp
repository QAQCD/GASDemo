// Fill out your copyright notice in the Description page of Project Settings.


#include "GStarAbsorbingMethodTA.h"
#include "GGameplayAbility.h"


AGStarAbsorbingMethodTA::AGStarAbsorbingMethodTA()
{
	PrimaryActorTick.bCanEverTick = true;
}

//开始确定目标
void AGStarAbsorbingMethodTA::StartTargeting(UGameplayAbility* Ability)
{
	OwningAbility = Ability;
	MasterPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
	SourceActor = Ability->GetOwningActorFromActorInfo();

	//技能的释放位置
	ConePoint = GetWorld()->SpawnActor<AActor>(ConePointClass, FVector::ZeroVector, FRotator::ZeroRotator);
}

//确认目标并继续
void AGStarAbsorbingMethodTA::ConfirmTargetingAndContinue()
{
	FVector ViewLocation;
	GetPlayerLookingPoint(ViewLocation);

	TArray<FOverlapResult> OverlapResults;
	TArray<TWeakObjectPtr<AActor>> OverlapActors;

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	QueryParams.bReturnPhysicalMaterial = false;
	if (SourceActor)
	{
		QueryParams.AddIgnoredActor(SourceActor->GetUniqueID());
	}

	bool TryOverlap = GetWorld()->OverlapMultiByObjectType(
			OverlapResults,
			ViewLocation,
			FQuat::Identity,
			FCollisionObjectQueryParams(ECC_Pawn),
			FCollisionShape::MakeSphere(Radius),
			QueryParams);

	if (TryOverlap)
	{
		for (FOverlapResult& OverlapResult: OverlapResults)
		{
			APawn* PawnOverlapped = Cast<APawn>(OverlapResult.Actor);
			if (PawnOverlapped)
			{
				OverlapActors.AddUnique(PawnOverlapped);
			}
		}
	}

	FVector MeteorSpawnLocation = ConePoint->GetActorLocation();
	MeteorSpawnLocation += ConePoint->GetActorUpVector() * 100.0f;
	Meteor = GetWorld()->SpawnActor<AActor>(MeteorClass, MeteorSpawnLocation, ConePoint->GetActorRotation());
	ConePoint->Destroy();


	OverlapActors.Add(Meteor);
	FGameplayAbilityTargetDataHandle TargetData = StartLocation.MakeTargetDataHandleFromActors(OverlapActors);
	TargetDataReadyDelegate.Broadcast(TargetData);
}

void AGStarAbsorbingMethodTA::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector LookLocation;
	GetPlayerLookingPoint(LookLocation);

	ConePoint->SetActorLocation(LookLocation);
}

bool AGStarAbsorbingMethodTA::GetPlayerLookingPoint(FVector& LookingPoint)
{

	FVector ViewVector;
	FRotator ViewRotation;
	if (MasterPC)
		MasterPC->GetPlayerViewPoint(ViewVector, ViewRotation);

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	if (SourceActor)
	{
		QueryParams.AddIgnoredActor(SourceActor->GetUniqueID());
	}

	FHitResult HitResult;


	//构建线路跟踪单通道,进行碰撞检测
	bool TryTrace = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			ViewVector,
			ViewVector + ViewRotation.Vector() * 10000.0f,
			ECollisionChannel::ECC_Visibility,
			QueryParams);

	if (TryTrace)
	{
		LookingPoint = HitResult.ImpactPoint;
	}
	else
	{
		LookingPoint = FVector::ZeroVector;
	}
	return TryTrace;
	
}
