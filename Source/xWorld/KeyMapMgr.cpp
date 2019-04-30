// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyMapMgr.h"

void UKeyMapMgr::AddActionMapping(const FInputActionKeyMapping& KeyMapping)
{
	ActionMappings.Add(KeyMapping);
}

void UKeyMapMgr::RemoveActionMapping(const FInputActionKeyMapping& KeyMapping)
{
	ActionMappings.Remove(KeyMapping);
}

void UKeyMapMgr::AddAxisMapping(const FInputAxisKeyMapping& KeyMapping)
{
	AxisMappings.Add(KeyMapping);
}

void UKeyMapMgr::RemoveAxisMapping(const FInputAxisKeyMapping& KeyMapping)
{
	AxisMappings.Remove(KeyMapping);
}
