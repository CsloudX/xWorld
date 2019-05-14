// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerInput.h"
#include "XBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XWORLD_API UXBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "XdLib")
	static void AddActionMapping(const FInputActionKeyMapping& ActionMapping);


	UFUNCTION(BlueprintCallable, Category = "XdLib")
	static void AddAxisMapping(const FInputAxisKeyMapping& AxisMapping);


};
