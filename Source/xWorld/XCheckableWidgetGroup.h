// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "UObject/Interface.h"
#include "XCheckableWidgetGroup.generated.h"


UINTERFACE()
class UXCheckableWidgetInterface : public UInterface
{
	GENERATED_BODY()
};
class XWORLD_API IXCheckableWidgetInterface
{
	GENERATED_BODY()

public:
	void SetChecked(bool bChecked);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "XCheckableWidget")
	int Check();

	//UFUNCTION(BlueprintNativeEvent, Category = "XCheckableWidget")
	//void OnSetChecked(bool bChecked);
	//virtual void OnSetChecked_Implementation(bool bChecked) {}

	//UPROPERTY(VisibleAnywhere, Category = "Snowing")
	//FOnCheck1 OnChecked; 
};

/**
 * 
 */
UCLASS()
class XWORLD_API UXCheckableWidgetGroup : public UCanvasPanel
{
	GENERATED_BODY()
};
