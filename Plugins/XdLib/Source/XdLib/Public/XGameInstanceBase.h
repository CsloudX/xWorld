// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "XSaveGameBase.h"
#include "XSysInfoSaveGame.h"
#include "XGameInstanceBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FXGameInstanceDateTimeChangedSignature, FDateTime, SysDateTime);

UCLASS()
class XDLIB_API UXGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<UXSaveGameBase*> SaveGameObjects;

	UPROPERTY()
	UXSysInfoSaveGame* SysInfoSaveGame;

	UPROPERTY()
	FTimerHandle SysDateTimeTimerHandle;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SysDateTimeTimerInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimespan SysDateTimeTimespan;

	UPROPERTY(BlueprintAssignable)
	FXGameInstanceDateTimeChangedSignature OnSysDateTimeChanged;
	
public:
	UXGameInstanceBase();

	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "SaveGameClass"))
	UXSaveGameBase* CreateSaveGameObject(TSubclassOf<UXSaveGameBase> SaveGameClass);

	virtual void Init() override;
	virtual void Shutdown() override;

	void SysDateTimeTick();
};
