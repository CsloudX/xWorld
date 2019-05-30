// Fill out your copyright notice in the Description page of Project Settings.

#include "XGameInstanceBase.h"
#include "Kismet/GameplayStatics.h"


UXGameInstanceBase::UXGameInstanceBase()
	:SysDateTimeTimerInterval(1),SysDateTimeTimespan(0,0,10)
{
}

UXSaveGameBase* UXGameInstanceBase::CreateSaveGameObject(TSubclassOf<UXSaveGameBase> SaveGameClass)
{
	UXSaveGameBase* ret = nullptr;
	if (*SaveGameClass == nullptr)
	{
		UE_LOG(LogScript, Warning, TEXT("UXGameInstanceBase::CreateSaveGame no class specified"));
		return ret;
	}

	FString SlotName = SaveGameClass.Get()->GetName();
	if (UGameplayStatics::DoesSaveGameExist(SlotName,0))
	{
		ret = Cast<UXSaveGameBase>( UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	}

	if (ret == nullptr)
	{
		ret = Cast<UXSaveGameBase>(UGameplayStatics::CreateSaveGameObject(SaveGameClass));
	}

	if (ret)
	{
		ret->SlotName = SlotName;
		ret->NeedSave = true;
		SaveGameObjects.Push(ret);
	}

	return ret;
}

void UXGameInstanceBase::Init()
{
	Super::Init();
	SysInfoSaveGame = Cast<UXSysInfoSaveGame>(CreateSaveGameObject(UXSysInfoSaveGame::StaticClass()));

	GetWorld()->GetTimerManager().SetTimer(SysDateTimeTimerHandle, this, &UXGameInstanceBase::SysDateTimeTick, SysDateTimeTimerInterval, true);
}

void UXGameInstanceBase::Shutdown()
{
	Super::Shutdown(); 

	for (auto itr = SaveGameObjects.CreateIterator(); itr; ++itr)
	{ 
		if ((*itr)->NeedSave) {
			UGameplayStatics::SaveGameToSlot((*itr), (*itr)->SlotName, 0);
		}
	}
}


void UXGameInstanceBase::SysDateTimeTick()
{
	SysInfoSaveGame->SysDateTime += SysDateTimeTimespan;
	OnSysDateTimeChanged.Broadcast(SysInfoSaveGame->SysDateTime);
}
