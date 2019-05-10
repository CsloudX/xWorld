// Fill out your copyright notice in the Description page of Project Settings.

#include "XTimerNumber.h"
#include "Engine.h"


UXTimerNumberBase::UXTimerNumberBase()
	:MinValue(0),MaxValue(100),CurrentValue(0), IncreaseTimerInterval(0.1), DecreaseTimerInterval(0.1)
	, IsExclusive(false)
{
}

UXTimerNumberBase::~UXTimerNumberBase()
{
}


void UXTimerNumberBase::BeginDestroy()
{
	StopIncrease();
	StopDecrease();

	UObject::BeginDestroy();
}

void UXTimerNumberBase::StartIncrease()
{
	StartIncreaseEx(IncreaseTimerInterval);
}
void UXTimerNumberBase::StartIncreaseEx(float Interval)
{
	if (IsExclusive)
	{
		StopDecrease();
	}
	GetWorld()->GetTimerManager().SetTimer(IncreaseTimerHandle, this, &UXTimerNumberBase::IncreaseTimerHandleTick, Interval, true);
	OnIncreaseStarted.Broadcast();
}
void UXTimerNumberBase::StopIncrease()
{
	if (IncreaseTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(IncreaseTimerHandle);
		OnIncreaseStopped.Broadcast();
	}
}
void UXTimerNumberBase::StartDecrease()
{
	StartDecreaseEx(DecreaseTimerInterval);
}
void UXTimerNumberBase::StartDecreaseEx(float Interval)
{
	if (IsExclusive)
	{
		StopIncrease();
	}
	GetWorld()->GetTimerManager().SetTimer(DecreaseTimerHandle, this, &UXTimerNumberBase::DecreaseTimerHandleTick, Interval, true);
	OnDecreaseStarted.Broadcast();
}
void UXTimerNumberBase::StopDecrease()
{
	if (DecreaseTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DecreaseTimerHandle);
		OnDecreaseStopped.Broadcast();
	}
}
void UXTimerNumberBase::IncreaseTick()
{
	if (GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
	{
		ReceiveIncreaseTick();
	}
}
void UXTimerNumberBase::DecreaseTick()
{
	if (GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
	{
		ReceiveDecreaseTick();
	}
}

void UXTimerNumberBase::IncreaseTimerHandleTick()
{
	float PreValue = CurrentValue;

	IncreaseTick();

	if (CurrentValue >= MaxValue)
	{
		CurrentValue = MaxValue;
		OnMaxValueArrived.Broadcast();
		StopIncrease();
	}

	if (CurrentValue != PreValue) 
	{
		OnValueChanged.Broadcast(CurrentValue);
	}
}
void UXTimerNumberBase::DecreaseTimerHandleTick()
{
	float PreValue = CurrentValue;

	DecreaseTick();

	if (CurrentValue <= MinValue)
	{
		CurrentValue = MinValue;
		OnMinValueArrived.Broadcast();
		StopDecrease();
	}

	if (CurrentValue != PreValue)
	{
		OnValueChanged.Broadcast(CurrentValue);
	}
}


//==================================================

UXTimerNumber::UXTimerNumber()
	:IncreaseRate(1), DecreaseRate(1)
{

}
UXTimerNumber::~UXTimerNumber() {}

void UXTimerNumber::IncreaseTick()
{
	CurrentValue += IncreaseRate;
}
void UXTimerNumber::DecreaseTick()
{
	CurrentValue -= DecreaseRate;
}
