// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FirstSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStats
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	float Health;

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	float Stamina;

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	float MaxStamina;

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	int32 Coins;

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	FVector Location;

	UPROPERTY(VisibleAnywhere, Category = "Player_Status")
	FRotator Rotation;


};

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API UFirstSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UFirstSaveGame();

	UPROPERTY(VisibleAnywhere,Category="Player_Basic")
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = "Player_Basic")
	uint32 UserIndex;

	UPROPERTY(VisibleAnywhere, Category = "Player_Basic")
	FCharacterStats CharacterStats;

};
