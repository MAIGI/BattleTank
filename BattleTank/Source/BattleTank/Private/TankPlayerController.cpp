// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "Misc/CoreMiscDefines.h"
#include "DrawDebugHelpers.h"


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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

//Get Controlled Tank
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		GetControlledTank()->AimAt(OutHitLocation);
	}
}

//Get Tank's Direction
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//Set ViewPortSize
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX*CrosshairLocationX,ViewPortSizeY*CrosshairLocationY);

	//Get CameraLookDirection
	FVector LookDirection;
	//UE_LOG(LogTemp,Warning,TEXT("Screen Location is : %s"), *ScreenLocation.ToString())
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		return true;
	}
	return false;
}

//Get Camera Location and Direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return (DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	));
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& OutHitLocation)const
{
	//OutHitResult
	FHitResult OutHitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		OutHitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		OutHitLocation = OutHitResult.Location;
		return true;
	}
	return false;
}



	//get world location of linetrace through crosshair
	//if it hit the landscape
	//tell controlled tank to aim at this point


