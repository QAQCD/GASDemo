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

	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxHealth);

	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxMana);

	//Attributes for Stamina����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Stamina);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
		FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxStamina);

	//����ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Shield);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")//�κεط�/��ͼ��д
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxShield);


	//���Ա仯ʱ���ص�
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;
};
