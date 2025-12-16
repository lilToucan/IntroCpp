// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_CustomGameInstanceSubsystem.h"

#include "Kismet/GameplayStatics.h"

void UCPP_CustomGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UCPP_CustomGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UCPP_CustomGameInstanceSubsystem::DoesSaveExist()
{
	return UGameplayStatics::DoesSaveGameExist(DefaultName, DefaultUserIndex);
}

bool UCPP_CustomGameInstanceSubsystem::LoadOrCreateSave()
{
	if (DoesSaveExist())
	{
		// LOADING:
		// 1 - Load existing saved game form disk
		USaveGame* LoadedSaveGame = UGameplayStatics::LoadGameFromSlot(DefaultName, DefaultUserIndex);

		if (!IsValid(LoadedSaveGame))
			return false;

		CurrentSave = Cast<UCustomSaveGame>(LoadedSaveGame);
		
		return IsValid(CurrentSave);
	}

// CREATE NEW SAVE GAME
	CurrentSave =  Cast<UCustomSaveGame>(UGameplayStatics::CreateSaveGameObject(UCustomSaveGame::StaticClass()));

	if (!IsValid(CurrentSave))
		return false;

	CurrentSave->Health = 100;
	CurrentSave-> UserIndex = DefaultUserIndex;
	return true;
	
}

bool UCPP_CustomGameInstanceSubsystem::SaveGame()
{
	if (!IsValid(CurrentSave))
		return false;

	// Save data in CurrentSaveGame
	CurrentSave->Health = 100;

	bool bSuccess = UGameplayStatics::SaveGameToSlot(CurrentSave,DefaultName,DefaultUserIndex);

	if (!bSuccess)
		return false;

	return true;
}

UCustomSaveGame* UCPP_CustomGameInstanceSubsystem::GetCurrentSavedGame()
{
	return CurrentSave;
}
