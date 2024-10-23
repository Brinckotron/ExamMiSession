// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExamenMiSessionGameMode.h"
#include "ExamenMiSessionCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExamenMiSessionGameMode::AExamenMiSessionGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
