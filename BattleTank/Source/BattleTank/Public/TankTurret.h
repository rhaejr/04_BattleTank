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
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 25; // default
	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegrees = 35;
	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegrees = 0;
	
};
