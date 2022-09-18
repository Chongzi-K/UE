// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_CPP_Actor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATest_CPP_Actor::ATest_CPP_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//启用复制功能
	//服务端调用spawn时，客户端也会生成，并且是由服务端复制信息到客户端，属于“同一个”actor
	//不勾选的时候，每个端自己决定是否生成，生成出来的也不是同一个actor
	bReplicates = true;

}

// Called when the game starts or when spawned
void ATest_CPP_Actor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		Health = 500.0f;
	}
	
}

// Called every frame
void ATest_CPP_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Sever Health= %f"),Health);

		Armor = FMath::Rand();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Client Health= %f"), Health);
	}

}

void ATest_CPP_Actor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATest_CPP_Actor, Health);
	DOREPLIFETIME(ATest_CPP_Actor,Armor);
}

void ATest_CPP_Actor::OnRep_Armor()
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Sever Armor= %f"), Armor);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Client Armor= %f"), Armor);
	}
}
