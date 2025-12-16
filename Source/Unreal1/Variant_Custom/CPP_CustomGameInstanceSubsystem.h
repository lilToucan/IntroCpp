// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CustomSaveGame.h"
#include "CPP_CustomGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL1_API UCPP_CustomGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UCustomSaveGame* CurrentSave;
	const FString DefaultName = TEXT("name");
	const int32 DefaultUserIndex = 0;

public:
	//subsystem initialization and deinitialization
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// checks if a save already exist
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="SaveGame")
	bool DoesSaveExist();

	UFUNCTION(BlueprintCallable,Category="SaveGame")
	bool LoadOrCreateSave(); 
	UFUNCTION(BlueprintCallable,Category="SaveGame")
	bool SaveGame();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="SaveGame")
	UCustomSaveGame* GetCurrentSavedGame();
};
