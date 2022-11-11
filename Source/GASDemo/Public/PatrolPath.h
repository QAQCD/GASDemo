// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

/**
 * 巡逻路线
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

	//公告板
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UBillboardComponent* Billboard;

	//箭头组件
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UArrowComponent* FacingDirection;

	//路径组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplinePath")
	class USplineComponent* Path;

	void GetSplinePoints();

	//返回的路径点
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplinePath")
	TArray<FVector> Locations;
};
