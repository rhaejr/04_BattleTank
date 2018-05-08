// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Yaw(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 5; // default
	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 35;
	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = 0;
	
};
