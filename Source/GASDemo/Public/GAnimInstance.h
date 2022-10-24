// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API UGAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	//自定义变量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacter")
	float Direction = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacter")
	float Speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacter")
	bool IsInAir = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacter")
	bool LookEvemy = false;
	
};