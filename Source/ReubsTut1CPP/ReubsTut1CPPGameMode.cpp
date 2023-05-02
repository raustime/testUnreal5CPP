// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReubsTut1CPPGameMode.h"
#include "ReubsTut1CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ReubsTut1CPPGameStateBase.h"

AReubsTut1CPPGameMode::AReubsTut1CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PointsToWin = 5;
}

void AReubsTut1CPPGameMode::OnTargetHit()
{
	if (AReubsTut1CPPGameStateBase* GS = Cast<AReubsTut1CPPGameStateBase>(GameState))
	{
		GS->Points++;

		if (GS->Points >= PointsToWin)
		{
			//UE_LOG(LogTemp, Warning, TEXT("You Win!"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("You Won the Game! It took you %f seconds to win the game "), GetWorld()->GetTimeSeconds()));
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("Your scored a point. Now you have %d points"), GS->Points);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Your scored a point. Now you have %d points"), GS->Points));
		}
	}
}
