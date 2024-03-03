// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"
#include "SMainMenuWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuPlayerController.h"
#include "MenuHUD.h"


AMenuGameMode::AMenuGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
