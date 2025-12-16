// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanvasStackBase.h"
#include "GameFramework/PlayerController.h"
#include "CPP_WidgetPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL1_API ACPP_WidgetPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//function
	TObjectPtr<UCanvasStackBase> GetCanvasStack();

protected:
	//variable
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD");
	TObjectPtr<UCanvasStackBase> canvasStackBase;
};
