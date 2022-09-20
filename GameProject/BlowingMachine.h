// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlowingMachine.generated.h"




UCLASS()
class FIRSTPROJECT_API ABlowingMachine : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ABlowingMachine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	class UStaticMeshComponent* Mesh_Basic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* Mesh_Wind;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Mesh")
	class USphereComponent* BlowingArea;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	FVector ActorLocation;

	UFUNCTION()
	virtual void BlowingAreaOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void BlowingAreaOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


		
};
