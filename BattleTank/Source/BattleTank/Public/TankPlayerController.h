// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
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
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 100000.0f;

	bool GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection)const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const ;
};
