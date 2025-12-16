// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_FPS_Character.h"
#include "CPP_FPS_InteractionComponent.h"
#include "CPP_PickUp.h"
#include "Damageable.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPP_FPS_Character::OnHitFunction()
{
	FString hp = FString::SanitizeFloat(HpComponent->CurrentHP);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *hp);
}

// Sets default values
ACPP_FPS_Character::ACPP_FPS_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creiamo la mesh da aggiungere nella gerarchia dei componenti visibil
	CompanionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Companion"));

	//... Altri settaggi relativi al componente

	CompanionMesh->SetupAttachment(RootComponent);

	//Creaimo il nostro componente di logica, uguale a quello visibile ma senza il setup attachment

	InteractionComponent = CreateDefaultSubobject<UCPP_FPS_InteractionComponent>(TEXT("Interaction"));

	InteractionComponent->RadiusInteraction = 200.f;
	InteractionComponent->DistanceInteraction = 1000.f;

	InteractionComponent->Transform.Add(FTransform());
	InteractionComponent->Transform.Add(FTransform());
	InteractionComponent->Transform.Add(FTransform());

	HpComponent = CreateDefaultSubobject<UCPP_HPComponent>(TEXT("HP"));
	HpComponent->OnHit.AddDynamic(this, &ACPP_FPS_Character::OnHitFunction);

	// HpComponent->OnHitTDelegate.BindDynamic(&ACPP_FPS_Character::OnHitFunction);
}

// Called when the game starts or when spawned
void ACPP_FPS_Character::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;

	GetWorld()->SpawnActor<AActor>(CompanionClass, GetActorTransform(), SpawnParams);

	//DrawDebugSphere(GetWorld(), GetActorLocation(), 100.f, 12, FColor::Blue, false, 5.f, (uint8)0U, 10.f);
}


// Called every frame
void ACPP_FPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<AActor*> ACPP_FPS_Character::OverlapSPhere()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> EobjectTypeQueryArray;
	EobjectTypeQueryArray.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
	UClass* actorTypeFilters = nullptr;
	TArray<AActor*> ignoreActors;
	TArray<AActor*> outActors;

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), 500.f, EobjectTypeQueryArray,
	                                          actorTypeFilters, ignoreActors, outActors);

	return outActors;
}

void ACPP_FPS_Character::PickupFunction(const FInputActionValue& InputActionValue)
{
	/* UE_LOG(LogTemp, Display,TEXT("PickingUp"))
	//
	// TArray<AActor*> hitActors = OverlapSPhere();
	//
	// for (AActor* a : hitActors)
	// {
	// 	ACPP_PickUp* pickUp;
	// 	if (!(a->GetClass()->IsChildOf(ACPP_PickUp::StaticClass())))
	// 	return;
	//
	// 	pickUp = Cast<ACPP_PickUp>(a);
	//
	// 	ItemsPickedUp.Add(pickUp);
	 }*
		if (ItemsPickedUp.Contains(a))
			continue;
		
		a->SetActorEnableCollision(false);
		a->SetActorHiddenInGame(true);
		a->SetActorTickEnabled(false);
		
		ItemsPickedUp.Add(a);
		*/

	TArray<AActor*> hitActors = OverlapSPhere();

	if (hitActors.Num() <= 0)
		return;

	for (AActor* a : hitActors)
	{
		if (!a->Implements<UDamageable>())
			continue;
		TScriptInterface<IDamageable> d = Cast<UDamageable>(a);

		if (d)
			continue;
		
		d.GetInterface()->Execute_ReceiveDamage(a,10);
		
	}
}

// Called to bind functionality to input
void ACPP_FPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInput->BindAction(PickupInputAction, ETriggerEvent::Started, this, &ACPP_FPS_Character::PickupFunction);
	}
}

void ACPP_FPS_Character::OnConstruction(const FTransform& Transforms)
{
}
