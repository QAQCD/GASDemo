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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxHealth);

	//法力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxMana);

	//Attributes for Stamina耐力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Stamina);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
		FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxStamina);

	//护盾值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Shield);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//任何地方/蓝图读写
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxShield);


	//属性变化时，回调
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;
};
