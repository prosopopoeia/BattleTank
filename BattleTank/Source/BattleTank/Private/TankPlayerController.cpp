// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}

	

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

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;//Out param
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	HitLocation = FVector(1.0);
	//find crosshair position
	int32 ViewportSizeX, ViewportSizeY;//size of viewport (i.e. the size of the view on screen)
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("screen location: %s"), *ScreenLocation.ToString());

	return true;
}
