// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMeunUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UMainMeunUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Setup();
	//void StartGame();

//private:
//	UPROPERTY(meta = (BindWidget))
//		class UButton*ButtonStart=nullptr;
	
	
};
