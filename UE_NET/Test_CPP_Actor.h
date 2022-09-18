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

	UPROPERTY(VisibleAnywhere,Replicated)//服务端生成的actor的数据会覆盖客户端生成
	float Health = 100.0f;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Armor)
	float Armor;

	UFUNCTION()
	void OnRep_Armor();

};





/*
Res_Notify 复制通知
如果一个变量设置为Res_Notify，当他发生复制时，服务端和收到该通知的客户端都能调用一个自定义函数
C++中仅在客户端调用函数，在服务端中调用需要采用RPC
*/

/*
RPC 可以实现 服务端调用客户端函数，客户端调用服务端函数
不可以有返回值
默认是不可靠的，需要 reliable 使其可靠
C++ 中 要把 Server \ Client \ NetMulticast 关键字添加到UFUNCTION中
蓝图中因为不能有返回值，所以不能用函数做RPC，要用事件
*/