// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "XSaveGameBase.generated.h"

/**
 * 
 */
UCLASS()
class XDLIB_API UXSaveGameBase : public USaveGame
{
	GENERATED_BODY()
	
public:
	FString SlotName;
	bool NeedSave;


	UFUNCTION(BlueprintCallable)
	void Dirty();
};
