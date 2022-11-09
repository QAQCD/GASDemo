// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GWeaponActor.h"
#include "GWeaponsManager.generated.h"


//����ö��ֵ˫���������ǵ�������
UENUM(BlueprintType)
enum class ESingleOrDouble : uint8
{
	Left,
	Right,
	Double
};


class AGWeaponActor;

//UCLASS ��������ӡ�Blueprintable����ͼ�̳�
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GASDEMO_API UGWeaponsManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGWeaponsManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
public:
	//�Զ���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons")
	ESingleOrDouble SingleOrDouble = ESingleOrDouble::Right;

	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta=(EditCondition = "SingleOrDouble == ESingleOrDouble::Left || SingleOrDouble == ESingleOrDouble::Double", EditConditionHides))
	TSubclassOf<AGWeaponActor> L_WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Left || SingleOrDouble == ESingleOrDouble::Double", EditConditionHides))
	FName L_SocketName;

	UPROPERTY(BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Left || SingleOrDouble == ESingleOrDouble::Double", EditConditionHides))
	AGWeaponActor* L_Weapon;

	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Right || SingleOrDouble == ESingleOrDouble::Double", EditConditionHides))
	TSubclassOf<AGWeaponActor> R_WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Right || SingleOrDouble == ESingleOrDouble::Double", EditConditionHides))
	FName R_SocketName;

	UPROPERTY(BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Right || SingleOrDouble == ESingleOrDouble::Double", EditConditionHides))
	AGWeaponActor* R_Weapon;
};