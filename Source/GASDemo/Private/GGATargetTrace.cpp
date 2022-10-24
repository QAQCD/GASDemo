// Fill out your copyright notice in the Description page of Project Settings.


#include "GGATargetTrace.h"
#include "GGameplayAbility.h"


void AGGATargetTrace::StartTargeting(UGameplayAbility* InAbility)
{	
	//碰撞形状以“线”开头，这是我们的默认值
	if (CollisionRadius > 0.0f)
	{
		//选中此处的“碰撞高度”，因为形状代码没有。用作半高
		if ((CollisionHeight * 0.5f) > CollisionRadius)
		{
			CollisionShape = FCollisionShape::MakeCapsule(CollisionRadius, CollisionHeight * 0.5f);
			CollisionHeightOffset = CollisionHeight * 0.5f;
		}
		else
		{
			CollisionShape = FCollisionShape::MakeSphere(CollisionRadius);
			CollisionHeight = 0.0f;
			CollisionHeightOffset = CollisionRadius;
		}
	}
	else
	{
		
		CollisionRadius = CollisionHeight = 0.0f;
	}
	Super::StartTargeting(InAbility);

}


FHitResult AGGATargetTrace::PerformTrace(AActor* InSourceActor)
{
	APlayerController* PC = OwningAbility->GetActorInfo().PlayerController.Get();
	check(PC);
	FHitResult HitResult;

	PC->GetHitResultUnderCursorByChannel(
		UEngineTypes::ConvertToTraceType(ECC_Visibility), false, HitResult);
	
	if (AActor* Actor = HitResult.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Func[%s]-> Hit the %s"),
			*FString(__FUNCTION__),
			*Actor->GetClass()->GetName());

		/* 条件判断，这里使用的是Actor下面的 Tag标签，可以通过其他方式 ，进行更复杂的判断 */
		bLastTraceWasGood = Actor->ActorHasTag("Ground");
		/* 依据检测结果，通过蓝图事件设置不同的演示效果 */
		SetStyleOfVisiableComponent(bLastTraceWasGood); 
	}
		return FHitResult();
}

bool AGGATargetTrace::IsConfirmTargetingAllowed()
{
	return bLastTraceWasGood;
}
