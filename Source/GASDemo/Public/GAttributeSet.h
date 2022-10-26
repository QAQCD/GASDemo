// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GAttributeSet.generated.h"

/**
 * 
 */


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class GASDEMO_API UGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UGAttributeSet();

	//生命
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Health);

	UFUNCTION(BlueprintCallable, Category = "BaseAttribute")
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	//法力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Mana);

	UFUNCTION(BlueprintCallable, Category = "BaseAttribute")
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

	//护盾值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Shield);

	UFUNCTION(BlueprintCallable, Category = "BaseAttribute")
	virtual void OnRep_Shield(const FGameplayAttributeData& OldShield);
};
