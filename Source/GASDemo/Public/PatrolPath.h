// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

/**
 * Ѳ��·��
 */

UCLASS()
class GASDEMO_API APatrolPath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrolPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	//�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UBillboardComponent* Billboard;

	//��ͷ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UArrowComponent* FacingDirection;

	//·�����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplinePath")
	class USplineComponent* Path;

	void GetSplinePoints();

	//���ص�·����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplinePath")
	TArray<FVector> Locations;
};
