// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPoolable.h"
#include "ObjectPoolSubsystem.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoidDelegate,AActor*);

USTRUCT(BlueprintType)
struct FObjectPool
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "object to Pool")
	TArray<TScriptInterface<IObjectPoolable>> ActivePoolingObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "object to Pool")
	TArray<TScriptInterface<IObjectPoolable>> InactivePoolingObjects;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInactiveObjectsChange, TSubclassOf<AActor>, ActorClass,float ,NumInactiveObjects);


UCLASS()
class UNREAL1_API UObjectPoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintType,BlueprintAssignable,BlueprintReadWrite, Category="Object Pool Subsystem")
	FInactiveObjectsChange OnInactivePoolingObjectsChanged;
	
	//FVoidDelegate OnActorDeactivate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Object Pool Subsystem")
	TMap<TSubclassOf<AActor>,FObjectPool> ObjectPoolMap;


	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	void AddPool(TSubclassOf<AActor> ActorClass, int32 initialSize = 1);

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	TScriptInterface<IObjectPoolable> GetActor(TSubclassOf<AActor> ActorClass);
	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	void ReturnActorToPool(TSubclassOf<AActor> ActorClass, TScriptInterface<IObjectPoolable> actorToReturn);
	
};
