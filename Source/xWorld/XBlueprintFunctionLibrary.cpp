// Fill out your copyright notice in the Description page of Project Settings.

#include "XBlueprintFunctionLibrary.h"

void UXBlueprintFunctionLibrary::AddActionMapping(const FInputActionKeyMapping& ActionMapping)
{
	UPlayerInput::AddEngineDefinedActionMapping(ActionMapping);
}

void UXBlueprintFunctionLibrary::AddAxisMapping(const FInputAxisKeyMapping & AxisMapping)
{
	UPlayerInput::AddEngineDefinedAxisMapping(AxisMapping);
}
