// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ReubsTut1CPPGameStateBase.generated.h"

/**
 *
 */
UCLASS()
class REUBSTUT1CPP_API AReubsTut1CPPGameStateBase: public AGameStateBase
{
	GENERATED_BODY()

public:

	AReubsTut1CPPGameStateBase();
	int32 Points;
};
