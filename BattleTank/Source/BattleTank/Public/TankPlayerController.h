// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:


	ATank* GetControlledTank() const;

	void BeginPlay()override;

	void Tick(float DeltaTime) override;
	
	//start the tank moving the barrel so that a shot would it where
	//the crosshari intersects the world 

	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector &OutHitLocation)const;

	UPROPERTY(EditAnywhere)
		float CrosshairLocationX=0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairLocationY=0.333f;

private:
	//OutHitResult
	FHitResult OutHitResult;

	//Location the PC is focused on 
	const FVector StartLocation = GetFocalLocation();

	//Multi 256 in facing direction of PC
	UPROPERTY(EditAnywhere)
	float LineLength=1000;
	const FVector EndLocation = StartLocation + GetControlRotation().Vector() * LineLength;
};
