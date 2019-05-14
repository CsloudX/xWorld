// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "XCarryNumber.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FXCarryNumberBaseValueChangedSignature, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FXCarryNumberBaseLevelChangedSignature, int, Level);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FXCarryNumberBaseEndValueChangedSignature, float, Value);

UCLASS(BlueprintType, Blueprintable)
class UXCarryNumberBase : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EndValue;

	UPROPERTY(BlueprintAssignable)
	FXCarryNumberBaseValueChangedSignature OnValueChanged;

	UPROPERTY(BlueprintAssignable)
	FXCarryNumberBaseLevelChangedSignature OnLevelChanged;

	UPROPERTY(BlueprintAssignable)
	FXCarryNumberBaseEndValueChangedSignature OnEndValueChanged;


public:
	UXCarryNumberBase();
	virtual ~UXCarryNumberBase();


	UFUNCTION(BlueprintCallable)
	void AddValue(float _Value);

	virtual void LevelChanged(int _Level);
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "LevelChanged"))
	void ReceiveLevelChanged(int _Level);

	UFUNCTION(BlueprintCallable)
	void SetEndValue(float _EndValue);
};

UCLASS(BlueprintType, Blueprintable)
class UXCarryNumber : public UXCarryNumberBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EndValueIncreaseRate;

public:
	UXCarryNumber();
	virtual ~UXCarryNumber();

	UFUNCTION(BlueprintCallable)
	void Initialize(int _Level = 1, float _Value = 0, float _EndValue = 100,float _EndValueIncreaseRate=1.5);

	virtual void LevelChanged(int _Level);
};
