// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREAL1_API IInteractable
{
	GENERATED_BODY()

public:
	float d;
	
	//mandatory function example 
	virtual void OnInteraction(AActor* actor) = 0;

	// mandatory function for blueprints
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,category="Interaction")
	void BlueprintOnInteraction(AActor* actor);
	
};
