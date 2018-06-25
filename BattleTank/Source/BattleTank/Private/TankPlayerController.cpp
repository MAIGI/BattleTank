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
		/*UE_LOG(LogTemp, Warning, TEXT("OutHitLocation is : %s"),*OutHitLocation.ToString())*/
	}

		//if (OutHitResult.GetActor())
		//{
		//	UE_LOG(LogTemp, Warning, TEXT("Hitted Actor is : %s"), *OutHitResult.GetActor()->GetName())
		//	/*UE_LOG(LogTemp, Warning, TEXT("Hitted Actor is : %s"), OutHitResult.Distance)*/
		//}
		//else
		//{
		//	UE_LOG(LogTemp, Warning, TEXT("No Hitted Actor"))
		//}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreeLocation = FVector2D(ViewPortSizeX*CrosshairLocationX,ViewPortSizeY*CrosshairLocationY);
	UE_LOG(LogTemp,Warning,TEXT("Screen Location is : %s"), *ScreeLocation.ToString())
	OutHitLocation=FVector(1.0f,1.0f,1.0f);
	return true;
}

	//get world location of linetrace through crosshair
	//if it hit the landscape
	//tell controlled tank to aim at this point


