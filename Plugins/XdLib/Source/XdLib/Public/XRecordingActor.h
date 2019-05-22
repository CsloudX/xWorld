// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XRecordingActor.generated.h"

UCLASS()
class XDLIB_API AXRecordingActor : public AActor
{
	GENERATED_BODY() 

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USceneCaptureComponent2D* Capture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMaterialInstanceDynamic* MaterialInstance;

private:
	
public:	
	// Sets default values for this actor's properties
	AXRecordingActor();

	UFUNCTION(BlueprintCallable)
	void Initialize(UPrimitiveComponent* TargetComponent, int32 Width,int32 Height, float FOV=45);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
