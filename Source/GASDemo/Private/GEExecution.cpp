// Fill out your copyright notice in the Description page of Project Settings.


#include "GEExecution.h"
#include "GAttributeSet.h"

struct DamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Shield)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health)

	DamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGAttributeSet, Shield, Target, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGAttributeSet, Health, Target, true);
	}
};

static DamageCapture& GetDamageCapture()
{
	static DamageCapture DamageCaptureVar;
	return DamageCaptureVar;
}

UGEExecution::UGEExecution()
{
	RelevantAttributesToCapture.Add(GetDamageCapture().ShieldDef);
	RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
	//
	ValidTransientAggregatorIdentifiers.AddTag(FGameplayTag::RequestGameplayTag("player.attack.Melee"));
}

void UGEExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecParams, FGameplayEffectCustomExecutionOutput& ExecOutputs) const
{
	float OutHealth = 0.0f;
	float OutShield = 0.0f;

	float ShielfMagnitude = 0.0f;
	float HealthMagnitude = 0.0f;
	float AttackDamage = 0.0f;

	ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().ShieldDef, FAggregatorEvaluateParameters(), ShielfMagnitude);
	ExecParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageCapture().HealthDef, FAggregatorEvaluateParameters(), HealthMagnitude);
	ExecParams.AttemptCalculateTransientAggregatorMagnitude(FGameplayTag::RequestGameplayTag("player.attack.Melee"), FAggregatorEvaluateParameters(), AttackDamage);

	OutShield = ShielfMagnitude - AttackDamage;
	if (OutShield < 0)
	{
		OutHealth = HealthMagnitude - fabs(OutShield);
		OutShield = 0;

		ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().ShieldProperty, EGameplayModOp::Override, OutShield));
		ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Override, OutHealth));
	}
	else
	{
		ExecOutputs.AddOutputModifier(FGameplayModifierEvaluatedData(GetDamageCapture().ShieldProperty, EGameplayModOp::Override, OutShield));
	}
}
