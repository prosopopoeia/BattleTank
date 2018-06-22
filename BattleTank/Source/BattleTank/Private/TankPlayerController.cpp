// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"


ATank * ATankPlayerController::GetControlledTank() const
{
	UE_LOG(LogTemp, Warning, TEXT("A tank made"));
	return Cast<ATank> (GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto controlledtank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("begin!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
	if (!controlledtank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NOT POSSESSING TANK"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("is possesing tank, !"));
	}
	UE_LOG(LogTemp, Warning, TEXT("Player controller begin playyyyyy!"));

}
