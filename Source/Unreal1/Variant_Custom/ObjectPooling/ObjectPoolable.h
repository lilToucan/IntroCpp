// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectPoolable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable, BlueprintType)
class UObjectPoolable : public UInterface
{
	GENERATED_BODY()
};

class UNREAL1_API IObjectPoolable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(ForceAsFunction), Category="Object Pool Subsystem")
	void BP_Activate();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(ForceAsFunction), Category="Object Pool Subsystem")
	void BP_Deactivate();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(ForceAsFunction), Category ="Object Pool Subsystem")
	void BP_UpdateTransform(FTransform GivenTransform, bool Sweep = true);
	
	//maybe? 
	// void UpdateTransform(FVector Location,FRotator Rotation, FVector Scale, bool Sweep = true);
};
