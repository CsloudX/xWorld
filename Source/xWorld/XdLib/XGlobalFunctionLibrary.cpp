// Fill out your copyright notice in the Description page of Project Settings.

#include "XGlobalFunctionLibrary.h"
#include "Engine.h"


void UXGlobalFunctionLibrary::XCreateObject(TSubclassOf<UObject> ObjectClass, UObject* Owner, UObject*& OutObject)
{
	if (*ObjectClass == nullptr)
	{
		UE_LOG(LogScript, Warning, TEXT("UXGlobalFunctionLibrary::XCreateObject no class specified"));
		return ;
	}

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(Owner);
	if (ObjectClass && World)
	{
		OutObject = NewObject<UObject>(World, ObjectClass);
	}
}

