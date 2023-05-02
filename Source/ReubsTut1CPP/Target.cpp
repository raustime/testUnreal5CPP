// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "GameplayTagContainer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATarget::ATarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh Component");
	StaticMesh->SetupAttachment(RootComponent);
	//SetRootComponent(StaticMesh);
	Tags.Add(FName("target"));
	MoveScale = 200.f;
}

void ATarget::ActorDeath_Implementation()
{

}

void ATarget::ActorDeathPure()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), bExplosion, GetActorTransform());
	Destroy();
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	MoveDirection = FMath::VRand();
}
// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector MoveDelta = MoveDirection * (FMath::Sin(GetWorld()->GetTimeSeconds() + DeltaTime) - FMath::Sin(GetWorld()->GetTimeSeconds())) * MoveScale;
	AddActorWorldOffset(MoveDelta, true);
}

