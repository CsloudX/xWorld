// Fill out your copyright notice in the Description page of Project Settings.

#include "XRecordingActor.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"


AXRecordingActor::AXRecordingActor()
{  
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Capture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Capture"));
	Capture->SetupAttachment(Camera);
	Capture->FOVAngle = 45; 
	Capture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
}

// Called when the game starts or when spawned
void AXRecordingActor::BeginPlay() 
{
	Super::BeginPlay();
	
}

void AXRecordingActor::BeginDestroy()
{
	Super::BeginDestroy();

	UKismetRenderingLibrary::ReleaseRenderTarget2D(Capture->TextureTarget);
}

// Called every frame
void AXRecordingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
} 

void AXRecordingActor::Initialize(UPrimitiveComponent* Target, int32 Width, int32 Height, float FOV)
{
	Capture->FOVAngle = FOV; 
	Capture->TextureTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), Width, Height);
	Capture->ShowOnlyComponent(Target);

	MaterialInstance = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GetWorld(), LoadObject<UMaterialInterface>(nullptr,
		TEXT("Material'/Game/XdLib/Widgets/RecordingImage/M_XRecording.M_XRecording'")));
	MaterialInstance->SetTextureParameterValue(FName("Image"), Capture->TextureTarget);
}

