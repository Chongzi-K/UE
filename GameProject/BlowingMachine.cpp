// Fill out your copyright notice in the Description page of Project Settings.


#include "BlowingMachine.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Main.h"
#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/MovementComponent.h"

// Sets default values for this component's properties
ABlowingMachine::ABlowingMachine()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh_Basic = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Basic"));
	SetRootComponent(Mesh_Basic);
	BlowingArea = CreateDefaultSubobject<USphereComponent>(TEXT("BlowingArea"));
	BlowingArea->SetupAttachment(GetRootComponent());


}


// Called when the game starts
void ABlowingMachine::BeginPlay()
{
	Super::BeginPlay();

	ActorLocation = GetActorLocation();

	BlowingArea->OnComponentBeginOverlap.AddDynamic(this, &ABlowingMachine::BlowingAreaOnOverlapBegin);
	BlowingArea->OnComponentEndOverlap.AddDynamic(this, &ABlowingMachine::BlowingAreaOnOverlapEnd);
}


// Called every frame
void ABlowingMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}

void ABlowingMachine::BlowingAreaOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap!"));
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			//FString Name = GetDebugName(Main);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *GetDebugName(Main));
			Main->GetMesh()->AddRadialImpulse(ActorLocation, 500.f, 2000.f, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}
	/*
	* 
	TArray<FHitResult> OutHits;

	FVector Start = ActorLocation;
	FVector End = ActorLocation;

	FCollisionShape MyColSphere = FCollisionShape::MakeSphere(500.0f);

	DrawDebugSphere(GetWorld(), ActorLocation, MyColSphere.GetSphereRadius(), 50, FColor::Cyan, true);


	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, Start, End, FQuat::Identity, ECC_Pawn, MyColSphere);
	if (isHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("isHit!"));

		for (auto& Hit : OutHits)
		{
			AMain* MeshComp = Cast<AMain>(OtherActor);
			//FString Name = GetDebugName(Hit.GetActor());
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *Name);
			if (MeshComp)
			{
				MeshComp->GetMovementComponent()->AddRadialImpulse(ActorLocation, 500.f, 2000.f, ERadialImpulseFalloff::RIF_Constant, true);
			}
		}
	}
	*/
}

void ABlowingMachine::BlowingAreaOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{

}

