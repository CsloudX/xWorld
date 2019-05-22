// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XRecordingWidget.generated.h"

/**
 * 
 */
UCLASS()
class UXRecordingWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	class UImage* Image;

public:
	UXRecordingWidget(const FObjectInitializer& ObjectInitializer);

	virtual bool Initialize() override;
};
