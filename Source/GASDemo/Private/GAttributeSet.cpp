// Fill out your copyright notice in the Description page of Project Settings.


#include "GAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"


UGAttributeSet::UGAttributeSet()
{
}


void UGAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMana()));
	}
}

