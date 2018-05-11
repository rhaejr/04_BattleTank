// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 10; // default
	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegrees = 35; 
	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegrees = 0; 
	
};
