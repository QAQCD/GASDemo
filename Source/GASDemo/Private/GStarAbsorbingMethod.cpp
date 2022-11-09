// Fill out your copyright notice in the Description page of Project Settings.


#include "GStarAbsorbingMethod.h"
#include "GGameplayAbility.h"


AGStarAbsorbingMethod::AGStarAbsorbingMethod()
{

}

void AGStarAbsorbingMethod::StartTargeting(UGameplayAbility* Ability)
{
	OwningAbility = Ability;
	//MasterPC是控制角色的Controller
	MasterPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
	//SourceActor:拥有调用TargeActor的Ability的Actor
	SourceActor = Ability->GetOwningActorFromActorInfo();
}

void AGStarAbsorbingMethod::ConfirmTargetingAndContinue()
{
	FVector AbilityStartLocation = FVector::ZeroVector;


	TArray<FOverlapResult> OverlapResults;
	TArray<TWeakObjectPtr<AActor>> OverlapActors;

	//构建碰撞检测的params
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	QueryParams.bReturnPhysicalMaterial = false;
	if (SourceActor)
	{
		QueryParams.AddIgnoredActor(SourceActor->GetUniqueID());
		AbilityStartLocation = SourceActor->GetActorLocation();
	}

	//构建球形碰撞体，进行碰撞检测
	bool TryOverlap = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		AbilityStartLocation,
		FQuat::Identity,
		FCollisionObjectQueryParams(ECC_Pawn),
		FCollisionShape::MakeSphere(Radius),
		QueryParams);

	//如果发生碰撞，将碰撞的actor写入OverlapActors
	if (TryOverlap)
	{
		for (const FOverlapResult& Result : OverlapResults)
		{
			APawn* OverlappedPawn = Cast<APawn>(Result.Actor);
			if (IsValid(OverlappedPawn))
			{
				OverlapActors.AddUnique(OverlappedPawn);
			}
		}
	}

	//如果OverlapActors存在数据，将数据通过delegate广播
	if (OverlapActors.Num() > 0)
	{
		const FGameplayAbilityTargetDataHandle TargetData = StartLocation.MakeTargetDataHandleFromActors(OverlapActors);
		TargetDataReadyDelegate.Broadcast(TargetData);
	}
}
