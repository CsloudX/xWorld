// Fill out your copyright notice in the Description page of Project Settings.

#include "XRecordingWidget.h"
#include "WidgetTree.h"
#include "Image.h"

UXRecordingWidget::UXRecordingWidget(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
}

bool UXRecordingWidget::Initialize()
{
	Image = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Image"));
	WidgetTree->RootWidget = Image;
	return true;
}
