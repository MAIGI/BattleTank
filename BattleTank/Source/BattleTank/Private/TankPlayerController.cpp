// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	APawn* ControlledTank = GetControlledTank();
	if (ControlledTank != nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Possessed Tank is : %s"),*ControlledTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No possessed Tank!"))
	}

}
