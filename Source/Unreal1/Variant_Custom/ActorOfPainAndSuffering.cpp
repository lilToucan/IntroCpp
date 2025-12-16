// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/ActorOfPainAndSuffering.h"

// Sets default values
AActorOfPainAndSuffering::AActorOfPainAndSuffering()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorOfPainAndSuffering::BeginPlay()
{
	Super::BeginPlay();

	CurrentHp = MaxHp;
}

// Called every frame
void AActorOfPainAndSuffering::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorOfPainAndSuffering::ReceiveDamage_Implementation(float DamageAmount)
{
	UE_LOG(LogTemp, Display, TEXT("Received Damage= %f"), DamageAmount);

	CurrentHp -= DamageAmount;
	if (CurrentHp > 0)
		return;

	
	UE_LOG(LogTemp, Display, TEXT("You are dead"));
}

