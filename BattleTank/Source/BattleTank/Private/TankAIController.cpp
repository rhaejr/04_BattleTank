// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// TODO Move towards player

		// Aim towards player
		
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire();
	}
}

//ATank* ATankAIController::GetControlledTank() const
//{
//	return ;
//
//}
//
//ATank* ATankAIController::GetPlayerTank() const
//{
//	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
//	if (!PlayerTank)
//	{
//		return nullptr;
//	}
//	else
//	{
//		return Cast<ATank>(PlayerTank);
//	}
//}

