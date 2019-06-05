// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Engine.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UPhysicsThrusterComponent
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{ 
	Super::BeginPlay();
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AWarrior::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWarrior::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AWarrior::MoveForward(float Value)
{
	if ((Controller != NULL))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Red, FString::Printf(TEXT("Forward: %f"), Value));
}
void AWarrior::MoveRight(float Value)
{
	if ((Controller != NULL))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Red, FString::Printf(TEXT("Right: %f"), Value));
}


