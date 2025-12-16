// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPoolable.h"
#include "GameFramework/Actor.h"
#include "CPP_PullableActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UNREAL1_API ACPP_PullableActor : public AActor, public IObjectPoolable
{
	GENERATED_BODY()

protected: // var
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sin")
	float Distance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sin")
	float Frequency = 1;

	FVector StartingLocation;
	FTimerHandle DeactivateSelfTimer ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UShapeComponent* CollisionComponent;

	UPROPERTY()
	UObjectPoolSubsystem* PoolSubsystem;

public: // func
	ACPP_PullableActor();
	virtual void Tick(float DeltaTime) override;
	virtual void BP_Activate_Implementation() override;
	virtual void BP_Deactivate_Implementation() override;
	virtual void BP_UpdateTransform_Implementation(FTransform GivenTransform, bool Sweep = true) override;

protected:
	virtual void BeginPlay() override;
};
