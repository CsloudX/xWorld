// Fill out your copyright notice in the Description page of Project Settings.

#include "XCarryNumber.h"


UXCarryNumberBase::UXCarryNumberBase()
	:Level(1),Value(0),EndValue(100)
{
	
}
UXCarryNumberBase::~UXCarryNumberBase() {}

void UXCarryNumberBase::AddValue(float _Value)
{
	Value = Value + _Value;
	while (Value >= EndValue)
	{
		Value -= EndValue;
		++Level;
		LevelChanged(Level);
		OnLevelChanged.Broadcast(Level);
	}

	OnValueChanged.Broadcast(Value);
}

void UXCarryNumberBase::SetEndValue(float _EndValue)
{
	check(_EndValue != 0);

	if (EndValue != _EndValue)
	{
		EndValue = _EndValue;
		AddValue(0);
	}
}

void UXCarryNumberBase::LevelChanged(int _Level)
{
	if (GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
	{
		ReceiveLevelChanged(_Level);
	}
}


UXCarryNumber::UXCarryNumber()
	:UXCarryNumberBase(),EndValueIncreaseRate(1.5)
{}
UXCarryNumber::~UXCarryNumber(){}

void UXCarryNumber::Initialize(int _Level, float _Value, float _EndValue, float _EndValueIncreaseRate)
{
	Level = _Level;
	Value = _Value;
	EndValueIncreaseRate = _EndValueIncreaseRate;
}

void UXCarryNumber::LevelChanged(int _Level)
{
	SetEndValue(EndValue * EndValueIncreaseRate);
}