// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damageable.h"
#include "GameFramework/Actor.h"
#include "ActorOfPainAndSuffering.generated.h"

UCLASS(blueprintable)
class UNREAL1_API AActorOfPainAndSuffering : public AActor, public IDamageable
{
	GENERATED_BODY()

public: // variables
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Healt")
	float MaxHp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Healt")
	float CurrentHp;


//public:  functions	

	AActorOfPainAndSuffering();
	virtual void Tick(float DeltaTime) override;

	virtual void ReceiveDamage_Implementation(float DamageAmount) override;;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
