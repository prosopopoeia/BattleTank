// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("cant find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("begin, have %s"), *(PlayerTank->GetName()));
	}
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//aim at player
		//fire when ready
		//auto aiTank = GetControlledTank();
		//FVector HitLocation;//Out param
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("hitdirection: %s"));
		//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
	}
	
	
	
	

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast <ATank> (GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//ATank* tankPlayer = Cast <ATank> player;
	if (!playerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("dont Have player controller for tank"));
		return nullptr;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("have player cont. for tank"));
		return Cast<ATank>(playerPawn);
	}
}