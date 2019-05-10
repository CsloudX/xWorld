// Fill out your copyright notice in the Description page of Project Settings.

#include "XBlueprintFunctionLibrary.h"
#include "Engine.h"

void UXBlueprintFunctionLibrary::AddActionMapping(const FInputActionKeyMapping& ActionMapping)
{
	UPlayerInput::AddEngineDefinedActionMapping(ActionMapping);
}

void UXBlueprintFunctionLibrary::AddAxisMapping(const FInputAxisKeyMapping & AxisMapping)
{
	UPlayerInput::AddEngineDefinedAxisMapping(AxisMapping);
}

UObject* UXBlueprintFunctionLibrary::SpawnObject(UObject* Owner, UClass* ObjClass)
{
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(Owner);
	return NewObject<UObject>(World, ObjClass);
}
