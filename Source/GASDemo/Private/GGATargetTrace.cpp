// Fill out your copyright notice in the Description page of Project Settings.


#include "GGATargetTrace.h"
#include "GGameplayAbility.h"


void AGGATargetTrace::StartTargeting(UGameplayAbility* InAbility)
{	
	//��ײ��״�ԡ��ߡ���ͷ���������ǵ�Ĭ��ֵ
	if (CollisionRadius > 0.0f)
	{
		//ѡ�д˴��ġ���ײ�߶ȡ�����Ϊ��״����û�С��������
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

		/* �����жϣ�����ʹ�õ���Actor����� Tag��ǩ������ͨ��������ʽ �����и����ӵ��ж� */
		bLastTraceWasGood = Actor->ActorHasTag("Ground");
		/* ���ݼ������ͨ����ͼ�¼����ò�ͬ����ʾЧ�� */
		SetStyleOfVisiableComponent(bLastTraceWasGood); 
	}
		return FHitResult();
}

bool AGGATargetTrace::IsConfirmTargetingAllowed()
{
	return bLastTraceWasGood;
}
