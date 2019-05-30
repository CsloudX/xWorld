// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "XTimerNumber.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FXTimerNumberValueChangedSignature, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FXTimerNumberIncreaseStartedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FXTimerNumberIncreaseStoppedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FXTimerNumberDecreaseStartedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FXTimerNumberDecreaseStoppedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FXTimerNumberMinValueArrivedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FXTimerNumberMaxValueArrivedSignature);

 
UCLASS(BlueprintType, Blueprintable)
class XDLIB_API UXTimerNumberBase : public UObject
{
	GENERATED_BODY()
		
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float IncreaseTimerInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DecreaseTimerInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsExclusive;

	UPROPERTY(BlueprintAssignable)
	FXTimerNumberValueChangedSignature OnValueChanged;

	UPROPERTY(BlueprintAssignable)
	FXTimerNumberIncreaseStartedSignature OnIncreaseStarted;
	UPROPERTY(BlueprintAssignable)
	FXTimerNumberIncreaseStoppedSignature OnIncreaseStopped;


	UPROPERTY(BlueprintAssignable)
	FXTimerNumberDecreaseStartedSignature OnDecreaseStarted;
	UPROPERTY(BlueprintAssignable)
	FXTimerNumberDecreaseStoppedSignature OnDecreaseStopped;

	UPROPERTY(BlueprintAssignable)
	FXTimerNumberMinValueArrivedSignature OnMinValueArrived;
	UPROPERTY(BlueprintAssignable)
	FXTimerNumberMaxValueArrivedSignature OnMaxValueArrived;

private:
	FTimerHandle IncreaseTimerHandle;
	FTimerHandle DecreaseTimerHandle;

public:
	UXTimerNumberBase();
	virtual ~UXTimerNumberBase();

	UFUNCTION(BlueprintCallable)
	void StartIncrease();
	UFUNCTION(BlueprintCallable)
	void StartIncreaseEx(float Interval=0.1);
	UFUNCTION(BlueprintCallable)
	void StopIncrease();


	UFUNCTION(BlueprintCallable)
	void StartDecrease();
	UFUNCTION(BlueprintCallable)
	void StartDecreaseEx(float Interval=0.1);
	UFUNCTION(BlueprintCallable)
	void StopDecrease();


	UFUNCTION(BlueprintCallable)
	void SafeSetValue(float _Value);

	virtual void IncreaseTick();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "IncreaseTick"))
	void ReceiveIncreaseTick();

	virtual void DecreaseTick();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "DecreaseTick"))
	void ReceiveDecreaseTick();

	void IncreaseTimerHandleTick();
	void DecreaseTimerHandleTick();

	virtual void BeginDestroy() override;

};

UCLASS(BlueprintType, Blueprintable)
class UXTimerNumber : public UXTimerNumberBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float IncreaseRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DecreaseRate;

public:
	UXTimerNumber();
	virtual ~UXTimerNumber();

	virtual void IncreaseTick() override;
	virtual void DecreaseTick() override;


	UFUNCTION(BlueprintCallable)
	void Initialize(float _MinValue = 0, float _MaxValue = 1, float _IncreaseTimerInterval=0.1, float _DecreaseTimerInterval = 0.1,
		float _IncreaseRate = 0.01, float _DecreaseRate = 0.01, bool _IsExclusive=true);
};
