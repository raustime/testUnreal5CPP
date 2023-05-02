// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DeathInterface.h"
#include "Target.generated.h"

UCLASS()
class REUBSTUT1CPP_API ATarget : public AActor, public IDeathInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATarget();

	void ActorDeath_Implementation() override;
	virtual void ActorDeathPure() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* StaticMesh;

	FVector MoveDirection;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MoveScale;
	UPROPERTY(EditDefaultsOnly, Category = "Particles")
		UParticleSystem* bExplosion = nullptr;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
