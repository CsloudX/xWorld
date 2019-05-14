// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XGlobalFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UXGlobalFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "ObjectClass", DynamicOutputParam = "OutObject"))
	static void XCreateObject(TSubclassOf<UObject> ObjectClass, UObject* Owner, UObject*& OutObject);
};
