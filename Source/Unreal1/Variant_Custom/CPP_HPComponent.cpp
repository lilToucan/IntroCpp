// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_HPComponent.h"

// Sets default values for this component's properties
UCPP_HPComponent::UCPP_HPComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_HPComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCPP_HPComponent::TakeDamage(float dmg)
{
	CurrentHP -= dmg;
	OnHpPercentChange.Broadcast(CurrentHP/MaxHp);
	if (CurrentHP <= 0)
	{
		OnDeath.Broadcast();
		return;
	}

	OnHit.Broadcast();
}




// Called every frame
void UCPP_HPComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

