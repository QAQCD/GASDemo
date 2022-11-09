// Fill out your copyright notice in the Description page of Project Settings.


#include "GStarAbsorbingMethod.h"
#include "GGameplayAbility.h"


AGStarAbsorbingMethod::AGStarAbsorbingMethod()
{

}

void AGStarAbsorbingMethod::StartTargeting(UGameplayAbility* Ability)
{
	OwningAbility = Ability;
	//MasterPC�ǿ��ƽ�ɫ��Controller
	MasterPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
	//SourceActor:ӵ�е���TargeActor��Ability��Actor
	SourceActor = Ability->GetOwningActorFromActorInfo();
}

void AGStarAbsorbingMethod::ConfirmTargetingAndContinue()
{
	FVector AbilityStartLocation = FVector::ZeroVector;


	TArray<FOverlapResult> OverlapResults;
	TArray<TWeakObjectPtr<AActor>> OverlapActors;

	//������ײ����params
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	QueryParams.bReturnPhysicalMaterial = false;
	if (SourceActor)
	{
		QueryParams.AddIgnoredActor(SourceActor->GetUniqueID());
		AbilityStartLocation = SourceActor->GetActorLocation();
	}

	//����������ײ�壬������ײ���
	bool TryOverlap = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		AbilityStartLocation,
		FQuat::Identity,
		FCollisionObjectQueryParams(ECC_Pawn),
		FCollisionShape::MakeSphere(Radius),
		QueryParams);

	//���������ײ������ײ��actorд��OverlapActors
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

	//���OverlapActors�������ݣ�������ͨ��delegate�㲥
	if (OverlapActors.Num() > 0)
	{
		const FGameplayAbilityTargetDataHandle TargetData = StartLocation.MakeTargetDataHandleFromActors(OverlapActors);
		TargetDataReadyDelegate.Broadcast(TargetData);
	}
}
