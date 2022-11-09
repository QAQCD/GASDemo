// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "GStarAbsorbingMethod.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API AGStarAbsorbingMethod : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()
	
public:
	AGStarAbsorbingMethod();

	//开始确定目标,只会调用一次 
	virtual void StartTargeting(UGameplayAbility* Ability) override;

	//确认目标并继续,请求目标数据，但不一定停止/销毁任务。用于外部目标数据请求
	virtual void ConfirmTargetingAndContinue();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = Targeting)
	float Radius;

};
