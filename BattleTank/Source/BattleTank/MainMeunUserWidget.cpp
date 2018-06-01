// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMeunUserWidget.h"
#include "UObject/ConstructorHelpers.h"

void UMainMeunUserWidget::Setup()
{
	this->AddToViewport();

	UWorld*World = GetWorld();

	APlayerController*PlayerController = World->GetFirstPlayerController();

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
}