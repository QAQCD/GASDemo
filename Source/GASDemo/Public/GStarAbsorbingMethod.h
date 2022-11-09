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

	//��ʼȷ��Ŀ��,ֻ�����һ�� 
	virtual void StartTargeting(UGameplayAbility* Ability) override;

	//ȷ��Ŀ�겢����,����Ŀ�����ݣ�����һ��ֹͣ/�������������ⲿĿ����������
	virtual void ConfirmTargetingAndContinue();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = Targeting)
	float Radius;

};
