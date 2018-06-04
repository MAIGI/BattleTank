// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMeunUserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/Button.h"

void UMainMeunUserWidget::Setup()
{
	this->AddToViewport();

	UWorld*World = GetWorld();

	APlayerController*PlayerController = World->GetFirstPlayerController();

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;

}

//void UMainMeunUserWidget::StartGame()
//{
//
//}
