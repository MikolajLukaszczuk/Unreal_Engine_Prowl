// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Prowl.h"
#include "ProwlGameMode.h"
#include "ProwlHUD.h"
#include "ProwlCharacter.h"

AProwlGameMode::AProwlGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProwlHUD::StaticClass();
}
