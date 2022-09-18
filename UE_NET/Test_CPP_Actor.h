// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test_CPP_Actor.generated.h"

UCLASS()
class UE_NET_API ATest_CPP_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest_CPP_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere,Replicated)//��������ɵ�actor�����ݻḲ�ǿͻ�������
	float Health = 100.0f;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Armor)
	float Armor;

	UFUNCTION()
	void OnRep_Armor();

};





/*
Res_Notify ����֪ͨ
���һ����������ΪRes_Notify��������������ʱ������˺��յ���֪ͨ�Ŀͻ��˶��ܵ���һ���Զ��庯��
C++�н��ڿͻ��˵��ú������ڷ�����е�����Ҫ����RPC
*/

/*
RPC ����ʵ�� ����˵��ÿͻ��˺������ͻ��˵��÷���˺���
�������з���ֵ
Ĭ���ǲ��ɿ��ģ���Ҫ reliable ʹ��ɿ�
C++ �� Ҫ�� Server \ Client \ NetMulticast �ؼ�����ӵ�UFUNCTION��
��ͼ����Ϊ�����з���ֵ�����Բ����ú�����RPC��Ҫ���¼�
*/