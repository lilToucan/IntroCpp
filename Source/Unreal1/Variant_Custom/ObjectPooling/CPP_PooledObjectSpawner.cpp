// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PooledObjectSpawner.h"



ACPP_PooledObjectSpawner::ACPP_PooledObjectSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_PooledObjectSpawner::BeginPlay()
{
	PoolSubsystem = GetWorld()->GetSubsystem<UObjectPoolSubsystem>();

	PoolSubsystem->AddPool(ActorClass);
	FireFunction();
	Super::BeginPlay();
}

void ACPP_PooledObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_PooledObjectSpawner::FireFunction()
{
	GetWorldTimerManager().ClearTimer(TimerHandle);
	
	if (!PoolSubsystem)
		return;

	TScriptInterface<IObjectPoolable> Poolable = PoolSubsystem->GetActor(ActorClass);
	if (!Poolable)
		return;

	TimerHandle = FTimerHandle();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACPP_PooledObjectSpawner::FireFunction, FireRate);

	// get a position in a sphere of radious ... Radious
	float randX = FMath::RandRange(-Radious, Radious);
	float randY = FMath::RandRange(-Radious, Radious);
	float randZ = FMath::RandRange(-Radious, Radious);
	FVector SpawnLocation = FVector(randX, randY, randZ) + GetActorLocation();

	FTransform newTransform;
	newTransform.SetLocation(SpawnLocation);
	newTransform.SetRotation(GetActorRotation().Quaternion());
	IObjectPoolable::Execute_BP_UpdateTransform(Poolable.GetObject(),newTransform,false);
}

