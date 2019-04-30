// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerInput.h"
#include "KeyMapMgr.generated.h"

/**
 * 
 */
UCLASS()
class XWORLD_API UKeyMapMgr : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "KeyMapMgr")
	void AddActionMapping(const FInputActionKeyMapping& KeyMapping);

	UFUNCTION(BlueprintCallable, Category = "KeyMapMgr")
	void RemoveActionMapping(const FInputActionKeyMapping& KeyMapping);

	UFUNCTION(BlueprintCallable, Category = "KeyMapMgr")
	void AddAxisMapping(const FInputAxisKeyMapping& KeyMapping);

	UFUNCTION(BlueprintCallable, Category = "KeyMapMgr")
	void RemoveAxisMapping(const FInputAxisKeyMapping& KeyMapping);
	
private:
	TArray<FInputActionKeyMapping>	ActionMappings;
	TArray<FInputAxisKeyMapping>	AxisMappings;
};
