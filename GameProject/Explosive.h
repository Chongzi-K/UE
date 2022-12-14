// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Explosive.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AExplosive : public AItem
{
	GENERATED_BODY()

public:
	AExplosive();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	float Damage;

	//父类已经有宏标记，子类就不能有
	//UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;

	//UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<UDamageType> DamageTypeClass;
};
