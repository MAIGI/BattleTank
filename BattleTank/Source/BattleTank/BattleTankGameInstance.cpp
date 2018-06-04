// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MainMeunUserWidget.h"

UBattleTankGameInstance::UBattleTankGameInstance(const FObjectInitializer&objectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget>MenuClassFinder(TEXT("'/Game/Tank/UI/MainMenu.MainMenu'"));
	if (MenuClassFinder.Class != nullptr)
	{
		TSubclassOf<class UUserWidget>MenuClass = MenuClassFinder.Class;
		Menu = CreateWidget<UMainMeunUserWidget>(this, MenuClass);
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Can not find MeunClassFinder!!!"))
	}
}

void UBattleTankGameInstance::LoadMainMenu()
{
	Menu->Setup();
	UE_LOG(LogTemp,Warning,TEXT("Work!!!"))
}
