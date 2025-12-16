// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_PickupActor.h"

#include "CPP_FPS_Character.h"

// Sets default values
ACPP_PickupActor::ACPP_PickupActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_PickupActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_PickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (!OtherActor->FindComponentByClass<UCPP_HPComponent>())
		return;
	
	UCPP_HPComponent* hpComp = OtherActor->GetComponentByClass<UCPP_HPComponent>();
	hpComp->TakeDamage(10.f);

	// Super::NotifyActorBeginOverlap(OtherActor);
}

// Called every frame
void ACPP_PickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
