// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XSaveGameBase.h"
#include "XSysInfoSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class XDLIB_API UXSysInfoSaveGame : public UXSaveGameBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FDateTime SysDateTime;

	UXSysInfoSaveGame();
};
