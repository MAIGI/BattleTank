// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* AIControlledTank = GetAIControlledTank();
	if (AIControlledTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("AIController Possessed Tank is %s"),*AIControlledTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("AIController not possessed Tank,Please Check !!!"))
	}
}

ATank* ATankAIController::GetAIControlledTank()const
{
	return Cast<ATank>(GetPawn());
}
