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
	
	/*  开始瞄准时调用，只会调用一次 */
	virtual void StartTargeting(UGameplayAbility* InAbility) override;

	/* 蓝图事件，可以根据检测结果，显示不同的效果*/
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
	/* 重中之重，重写PerformTrace方法*/
	virtual FHitResult PerformTrace(AActor* InSourceActor) override;

	/* 确认方法，若返回false，即便是进行Confirm操作也会被阻塞*/
	virtual bool IsConfirmTargetingAllowed() override;

	/* 布尔flag，单纯用来判断 结果是否有效 */
	bool bLastTraceWasGood;
	
	
};