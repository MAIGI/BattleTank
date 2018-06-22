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

	const UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp,Warning,TEXT("World is Empty!!!"))
	}

	//Location the PC is focused on 
	const FVector StartLocation = GetFocalLocation();

	//Multi 256 in facing direction of PC
	const FVector EndLocation = StartLocation + GetControlRotation().Vector() * 1000;

	FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")),true,GetControlledTank());
	TraceParams.bTraceComplex = true;
	FHitResult HittedActor = FHitResult(ForceInit);

	World->LineTraceSingleByChannel
	(
		HittedActor,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_WorldStatic,
		TraceParams
	);

	DrawDebugLine
	(
		GetWorld(),
		StartLocation,
		EndLocation,
		FColor::Red,
		0.0f,
		-1,
		12.333
	);

	if (HittedActor.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Hitted Actor is : %s"),*HittedActor.GetActor()->GetName())
		UE_LOG(LogTemp, Warning, TEXT("Hitted Actor is : %s"), HittedActor.Distance)
	}


	//get world location of linetrace through crosshair
	//if it hit the landscape
	//tell controlled tank to aim at this point
}


