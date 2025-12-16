// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PullableActor.h"

#include "ObjectPoolSubsystem.h"
#include "Components/BoxComponent.h"


// Sets default values
ACPP_PullableActor::ACPP_PullableActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_PullableActor::BeginPlay()
{
	PoolSubsystem = GetWorld()->GetSubsystem<UObjectPoolSubsystem>();
	StartingLocation = GetActorLocation();
	DeactivateSelfTimer = FTimerHandle();
	GetWorldTimerManager().SetTimer(DeactivateSelfTimer, this, &ACPP_PullableActor::BP_Deactivate_Implementation, 4.f);
	Super::BeginPlay();
}

void ACPP_PullableActor::BP_Activate_Implementation()
{
	GetWorldTimerManager().ClearTimer(DeactivateSelfTimer);
	DeactivateSelfTimer = FTimerHandle();
	GetWorldTimerManager().SetTimer(DeactivateSelfTimer, this, &ACPP_PullableActor::BP_Deactivate_Implementation, 4.f);
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	SetActorEnableCollision(true);
	StartingLocation = GetActorLocation();
}

void ACPP_PullableActor::BP_Deactivate_Implementation()
{
	if (!PoolSubsystem)
		return;
	
	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

	FTransform NewTransform = FTransform::Identity;
	NewTransform.SetLocation(FVector::ZeroVector);
	Execute_BP_UpdateTransform(this,NewTransform,false);
	PoolSubsystem->ReturnActorToPool(GetClass(),TScriptInterface<IObjectPoolable>(this));
}

void ACPP_PullableActor::BP_UpdateTransform_Implementation(FTransform GivenTransform, bool Sweep)
{
	SetActorTransform(GivenTransform, Sweep);
	StartingLocation = GetActorLocation();
}

void ACPP_PullableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector sinLocation = StartingLocation + (FVector::RightVector * (sin(GetWorld()->GetTimeSeconds() / Frequency) * Distance));
	SetActorLocation(sinLocation);
}
