// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/BFL_HUDHelper.h"

#include "CPP_WidgetPlayerController.h"
#include "CommonUI/Public/CommonActivatableWidget.h"
#include "GameFramework/GameSession.h"
#include "Kismet/GameplayStatics.h"

void UBFL_HUDHelper::PushWidget(const UObject* World, TSubclassOf<UCommonActivatableWidget> WidgetToPush)
{
	ACPP_WidgetPlayerController* controller = Cast<ACPP_WidgetPlayerController>(UGameplayStatics::GetPlayerController(World, 0));
	if (!IsValid(controller))
	{
		UE_LOG(LogTemp, Log, TEXT("no Controller"));
		return;
	}

	controller->GetCanvasStack()->PushWidget(WidgetToPush);
}

void UBFL_HUDHelper::RemoveWidget(const UObject* World, UCommonActivatableWidget* WidgetToRemove)
{
	ACPP_WidgetPlayerController* controller = Cast<ACPP_WidgetPlayerController>(UGameplayStatics::GetPlayerController(World, 0));
	controller->GetCanvasStack()->RemoveWidget(WidgetToRemove);
}
