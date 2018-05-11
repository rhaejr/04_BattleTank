// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void SetBarrelReferance(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable)
	void SetTurretReferance(UTankTurret * TurretToSet);
	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UTankAimingComponent * TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, CAtegory = Firing)
	float LaunchSpeed = 6000.0; // TODO find sensible default

	
	
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
};
