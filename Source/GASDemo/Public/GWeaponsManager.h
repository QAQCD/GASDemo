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
	SingleOrDouble
};


class USceneComponent;

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta=(EditCondition = "SingleOrDouble == ESingleOrDouble::Left || SingleOrDouble == ESingleOrDouble::SingleOrDouble", EditConditionHides))
	TSubclassOf<AActor> L_WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Left || SingleOrDouble == ESingleOrDouble::SingleOrDouble", EditConditionHides))
	FName L_SocketName;


	//����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Right || SingleOrDouble == ESingleOrDouble::SingleOrDouble", EditConditionHides))
	TSubclassOf<AGWeaponActor> R_WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons", meta = (EditCondition = "SingleOrDouble == ESingleOrDouble::Right || SingleOrDouble == ESingleOrDouble::SingleOrDouble", EditConditionHides))
	FName R_SocketName;

};