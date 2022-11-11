// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolPath.h"
#include "Components\BillboardComponent.h"
#include "Components\ArrowComponent.h"
#include "Components\SplineComponent.h"


// Sets default values
APatrolPath::APatrolPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//SetupAttachment ���ø���
	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(GetRootComponent());
	RootComponent = Billboard;

	FacingDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("FacingDirection"));
	FacingDirection->SetupAttachment(Billboard);

	//·����
	Path = CreateDefaultSubobject<USplineComponent>(TEXT("Path"));
	Path->SetupAttachment(Billboard);
	Path->bDrawDebug = true;
}

// Called when the game starts or when spawned
void APatrolPath::BeginPlay()
{
	Super::BeginPlay();
	GetSplinePoints();
}

// Called every frame
void APatrolPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//����·����
void APatrolPath::GetSplinePoints()
{
	for (int i = 0; i <= Path->GetNumberOfSplinePoints(); ++i)
	{
		Locations.Add(Path->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World));
	}
}

