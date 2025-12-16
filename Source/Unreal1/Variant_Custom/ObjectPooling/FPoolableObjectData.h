#pragma once

#include "CoreMinimal.h"


#include "FPoolableObjectData.generated.h"

USTRUCT(BlueprintType)
struct FPoolableObjectData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// Name to expose once the object is spawned
	// used also to search the data row
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Poolable")
	FText PoolableObjectName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Poolable")
	TSoftObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Poolable")
	TSoftObjectPtr<UMaterialInterface> Material;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Poolable")
	FVector Scale = FVector(1.0f, 1.0f, 1.0f);
};
