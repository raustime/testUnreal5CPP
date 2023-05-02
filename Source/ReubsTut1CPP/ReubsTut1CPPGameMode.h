// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ReubsTut1CPPGameMode.generated.h"

UCLASS(minimalapi)
class AReubsTut1CPPGameMode: public AGameModeBase
{
	GENERATED_BODY()

public:
	AReubsTut1CPPGameMode();

	void OnTargetHit();

	UPROPERTY(EditAnywhere, Category = "Game Rules")
		int32 PointsToWin;
};



