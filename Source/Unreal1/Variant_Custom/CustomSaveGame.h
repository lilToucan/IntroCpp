// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CustomSaveGame.generated.h"

// struct to save player data
USTRUCT(BlueprintType)
struct FSaveDataPlayer
{
	GENERATED_BODY();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category="SaveData")
	FVector PlayerLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category="SaveData")
	FRotator PlayerRotation;
};

UCLASS()
class UNREAL1_API UCustomSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(visibleAnywhere, Category="SaveData")
	FString SaveSlotName;
	UPROPERTY(visibleAnywhere, Category="SaveData")
	int32 UserIndex;
	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category="SaveData")
	float Health;
	UPROPERTY(visibleAnywhere, BlueprintReadWrite, Category="SaveData")
	TMap<int32,int> inventoryItems; // Key: itemID, Value: Quantity
};
