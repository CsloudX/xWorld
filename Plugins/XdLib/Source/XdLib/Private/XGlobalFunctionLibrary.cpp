// Fill out your copyright notice in the Description page of Project Settings.

#include "XGlobalFunctionLibrary.h"
#include "Engine.h"
#include "Kismet/KismetSystemLibrary.h"


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


FTimerHandle UXGlobalFunctionLibrary::XReentrantSetTimerByEvent(FTimerDynamicDelegate Delegate, float Time, bool bLooping)
{
	FTimerHandle Handle;
	if (Delegate.IsBound())
	{
		const UWorld* const World = GEngine->GetWorldFromContextObject(Delegate.GetUObject(), EGetWorldErrorMode::LogAndReturnNull);
		if (World)
		{
			FTimerManager& TimerManager = World->GetTimerManager();
			//Handle = TimerManager.K2_FindDynamicTimerHandle(Delegate);
			TimerManager.SetTimer(Handle, Delegate, Time, bLooping);
		}
	}
	else
	{
		UE_LOG(LogBlueprintUserMessages, Warning,
			TEXT("SetTimer passed a bad function (%s) or object (%s)"),
			*Delegate.GetFunctionName().ToString(), *GetNameSafe(Delegate.GetUObject()));
	}

	return Handle;
}
