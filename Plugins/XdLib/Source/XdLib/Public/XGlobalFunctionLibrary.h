// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XGlobalFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDLIB_API UXGlobalFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "ObjectClass", DynamicOutputParam = "OutObject"))
	static void XCreateObject(TSubclassOf<UObject> ObjectClass, UObject* Owner, UObject*& OutObject);

	UFUNCTION(BlueprintCallable)
	static FTimerHandle XReentrantSetTimerByEvent(UPARAM(DisplayName = "Event") FTimerDynamicDelegate Delegate, float Time, bool bLooping);

};
