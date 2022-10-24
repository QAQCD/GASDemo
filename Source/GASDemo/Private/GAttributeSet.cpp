// Fill out your copyright notice in the Description page of Project Settings.


#include "GAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"


UGAttributeSet::UGAttributeSet()
{
}

void UGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	//Health
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}//Mana
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
	}//Stamina
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));
	}//Shield
	if (Data.EvaluatedData.Attribute == GetShieldAttribute())
	{
		SetStamina(FMath::Clamp(GetShield(), 0.0f, GetMaxShield()));
	}
}

