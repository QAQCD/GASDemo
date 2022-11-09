// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "GStarAbsorbingMethodTA.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API AGStarAbsorbingMethodTA : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:

	AGStarAbsorbingMethodTA();

	//��ʼȷ��Ŀ��
	virtual void StartTargeting(UGameplayAbility* Ability) override;

	//ȷ��Ŀ�겢����
	virtual void ConfirmTargetingAndContinue() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Settings", meta = (ExposeOnSpawn = true))
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Settings", meta = (ExposeOnSpawn = true))
	TSubclassOf<AActor> ConePointClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability Settings", meta = (ExposeOnSpawn = true))
	TSubclassOf<AActor> MeteorClass;

	// ��ȡ������������ײ��
	UFUNCTION(BlueprintCallable, Category = "Chikabu Tensei")
	bool GetPlayerLookingPoint(FVector& LookingPoint);

protected:
	UPROPERTY()
	AActor* ConePoint;

	UPROPERTY()
	AActor* Meteor;
	
};
