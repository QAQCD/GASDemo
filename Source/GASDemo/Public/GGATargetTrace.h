// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor_Trace.h"
#include "GGATargetTrace.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API AGGATargetTrace : public AGameplayAbilityTargetActor_Trace
{
	GENERATED_BODY()

public:
	
	/*  ��ʼ��׼ʱ���ã�ֻ�����һ�� */
	virtual void StartTargeting(UGameplayAbility* InAbility) override;

	/* ��ͼ�¼������Ը��ݼ��������ʾ��ͬ��Ч��*/
	UFUNCTION(BlueprintImplementableEvent, Category = "Targeting")
	void SetStyleOfVisiableComponent(bool bWasRightPosition);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = Targeting)
	float CollisionRadius;

	/** Height for a capsule. Implicitly indicates a capsule is desired if this is greater than zero. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = Targeting)
	float CollisionHeight;

	FCollisionShape CollisionShape;

	float CollisionHeightOffset = 0.0f;


protected:
	/* ����֮�أ���дPerformTrace����*/
	virtual FHitResult PerformTrace(AActor* InSourceActor) override;

	/* ȷ�Ϸ�����������false�������ǽ���Confirm����Ҳ�ᱻ����*/
	virtual bool IsConfirmTargetingAllowed() override;

	/* ����flag�����������ж� ����Ƿ���Ч */
	bool bLastTraceWasGood;
	
	
};