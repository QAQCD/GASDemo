// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExecution.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API UGEExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UGEExecution();

	void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams, FGameplayEffectCustomExecutionOutput& ExecOutputs) const;
};
