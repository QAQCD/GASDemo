// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//�������
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GGameplayAbility.h"

#include "GCharacter.generated.h"


class UGAttributeSet;
class AGWeaponActor;

UCLASS()
class GASDEMO_API AGCharacter : public ACharacter, 
	public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
	UAbilitySystemComponent* AbilitySystemComp;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TArray<TSubclassOf<UGameplayAbility>> MyAbilities;

	//�����Ϸ��ǩ
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void AddLooseGameplayTag(FGameplayTag TagToAdd);

	//�Ƴ���Ϸ��ǩ
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void RemoveLooseGameplayTag(FGameplayTag TagToReamove);


	//����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
		const class UGAttributeSet* BaseAttributeSetComp;

	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
		void GetHealthValues(float& Health, float& MaxHealth);

	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
		void GetManaValues(float& Mana, float& MaxMana);

	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
		void GetStaminaValues(float& Stamina, float& MaxStamina);


	//���Ա仯
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnHealthChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnManaChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnStaminaChanged(float OldValue, float NewValue);


	void OnHealthChageNative(const FOnAttributeChangeData& Data);
	void OnManaChageNative(const FOnAttributeChangeData& Data);
	void OnStaminaChageNative(const FOnAttributeChangeData& Data);

	//�Զ������
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
	bool LookEvemy;
};