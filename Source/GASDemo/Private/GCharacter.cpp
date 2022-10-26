// Fill out your copyright notice in the Description page of Project Settings.


#include "GCharacter.h"
#include "AbilitySystemComponent.h"
#include "GAttributeSet.h"




// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//GAS
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");

	GAttributeSetComp = CreateDefaultSubobject<UGAttributeSet>("GAttributeSetComp");

}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();

	//技能数组
	if (nullptr != AbilitySystemComp)
	{
		// 修改：给ASC赋予技能
		if (HasAuthority() && MyAbilities.Num() > 0)
		{
			for (auto i = 0; i < MyAbilities.Num(); i++)
			{
				if (MyAbilities[i] == nullptr)
				{
					continue;
				}
				AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(MyAbilities[i].GetDefaultObject(), 1, 0));
			}
		}
		// 修改：初始化ASC
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
	//属性
	if (AbilitySystemComp)
	{
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(UGAttributeSet::GetHealthAttribute()).AddUObject(this, &AGCharacter::OnHealthChageNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(UGAttributeSet::GetManaAttribute()).AddUObject(this, &AGCharacter::OnManaChageNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(UGAttributeSet::GetShieldAttribute()).AddUObject(this, &AGCharacter::OnShieldChageNative);
		
	}

}

// Called every frame
void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AGCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}


//添加移除tag
void AGCharacter::AddLooseGameplayTag(FGameplayTag TagToAdd)
{
	GetAbilitySystemComponent()->AddLooseGameplayTag(TagToAdd);
	GetAbilitySystemComponent()->SetTagMapCount(TagToAdd, 1);
}

void AGCharacter::RemoveLooseGameplayTag(FGameplayTag TagToReamove)
{
	GetAbilitySystemComponent()->RemoveLooseGameplayTag(TagToReamove);
}

//属性变化
void AGCharacter::OnHealthChageNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void AGCharacter::OnManaChageNative(const FOnAttributeChangeData& Data)
{
	OnManaChanged(Data.OldValue, Data.NewValue);
}

void AGCharacter::OnShieldChageNative(const FOnAttributeChangeData& Data)
{
	OnShieldChanged(Data.OldValue, Data.NewValue);
}