// Fill out your copyright notice in the Description page of Project Settings.


#include "GAttributeSet.h"


UGAttributeSet::UGAttributeSet()
{
}

void UGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Health, OldHealth);
}

void UGAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Health, OldMana);
}

void UGAttributeSet::OnRep_Shield(const FGameplayAttributeData& OldShield)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Health, OldShield);
}

