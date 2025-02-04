// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	//ATank * GetControlledTank() const;
	void BeginPlay() override;
	//ATank* GetPlayerTank() const;
	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadius = 3000;

};
