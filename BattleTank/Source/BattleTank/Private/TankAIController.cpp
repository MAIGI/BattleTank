// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = GetPlayerTank();;
	if (PlayerTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("AI'Tank get Player'Tank : %s"),*PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("AI'Tank can't find  Player'Tank "))
	}
}

ATank* ATankAIController::GetAIControlledTank()const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto AIGettedPlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (AIGettedPlayerTank) { return Cast<ATank>(AIGettedPlayerTank); }
	else { return nullptr; }
}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		auto PlayerTankLocation = GetPlayerTank()->GetActorLocation();
		GetAIControlledTank()->AimAt(PlayerTankLocation);
	}
}
