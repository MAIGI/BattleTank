// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MainMeunUserWidget.h"

UBattleTankGameInstance::UBattleTankGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget>MenuClassFinder(TEXT("'/Game/Tank/UI/MainMenu.MainMenu'"));
	TSubclassOf<class UUserWidget>MenuClass = MenuClassFinder.Class;

	UMainMeunUserWidget * Menu = CreateWidget<UMainMeunUserWidget>(this, MenuClass);

}

