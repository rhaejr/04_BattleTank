// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto TargetedTank = GetPlayerTank();
	if (!TargetedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find Player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController targeting Player: %s"), *TargetedTank->GetName());
	}


}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerTank);
	}
}

