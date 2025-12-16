// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPoolSubsystem.h"
#include "GameFramework/Actor.h"
#include "CPP_PooledObjectSpawner.generated.h"

UCLASS()
class UNREAL1_API ACPP_PooledObjectSpawner : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (MustImplement = "ObjectPoolable"),Category="Spawning")
	TSubclassOf<AActor> ActorClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawning")
	float FireRate = 1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawning")
	float Radious = 300;
	
	// Sets default values for this actor's properties
	ACPP_PooledObjectSpawner();

protected:
	UPROPERTY()
	UObjectPoolSubsystem* PoolSubsystem;
	FTimerHandle TimerHandle;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void FireFunction();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
