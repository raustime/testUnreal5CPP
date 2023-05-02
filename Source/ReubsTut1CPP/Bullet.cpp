// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ReubsTut1CPPGameMode.h"
#include "Target.h"

// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh Component");
	SetRootComponent(StaticMesh);

	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Bullet Movement");
	BulletMovement->InitialSpeed = 2000.f;
	BulletMovement->MaxSpeed = 2000.f;

	OnActorHit.AddDynamic(this, &ABullet::OnBulletHit);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// void ABullet::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
// {
// 	// Check if the OtherActor is the actor we're interested in
// 	if (OtherActor->ActorHasTag("target"))
// 	{
// 		if (AReubsTut1CPPGameMode* GM = Cast<AReubsTut1CPPGameMode>(GetWorld()->GetAuthGameMode()))
// 		{
// 			GM->OnTargetHit();
// 		}
// 	}
// 	Destroy();
// }

void ABullet::OnBulletHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->ActorHasTag(FName("target")))
	{

		//if (AReubsTut1CPPGameMode* GM = Cast<AReubsTut1CPPGameMode>(GetWorld()->GetAuthGameMode()))
		if (AReubsTut1CPPGameMode* GM = GetWorld()->GetAuthGameMode<AReubsTut1CPPGameMode>())
		{
			GM->OnTargetHit();
		}
		IDeathInterface* Interface = Cast<IDeathInterface>(OtherActor);
		if (Interface)
		{
			Interface->ActorDeathPure();
			Interface->Execute_ActorDeath(OtherActor);
		}
	}
	Destroy();
}




