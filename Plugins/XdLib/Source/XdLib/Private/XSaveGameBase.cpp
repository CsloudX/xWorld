// Fill out your copyright notice in the Description page of Project Settings.

#include "XSaveGameBase.h"

void UXSaveGameBase::Dirty()
{
	NeedSave = true;
}
