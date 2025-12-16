// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_HPComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAfterHitDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHpPercentDelegate, float, hpPercent);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREAL1_API UCPP_HPComponent : public UActorComponent
{
	GENERATED_BODY()

public: // variables
	UPROPERTY(EditAnywhere, Blueprintreadwrite, Category="Health")
	float MaxHp = 100;

	UPROPERTY(BlueprintAssignable,Category="Health")
	FAfterHitDelegate OnHit;

	UPROPERTY(BlueprintAssignable,Category="Health")
	FAfterHitDelegate OnDeath;
	
	UPROPERTY(BlueprintAssignable,Category="Health")
	FHpPercentDelegate OnHpPercentChange;

	//TBaseDynamicDelegate<void,void,void> OnHitTDelegate;

	UPROPERTY(Blueprintreadwrite, Category="Health")
	float CurrentHP = 100;
protected: // variables

public: // functions
	// Sets default values for this component's properties
	void TakeDamage(float dmg);
	UCPP_HPComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

protected: // functions
	// Called when the game starts
	virtual void BeginPlay() override;
};
