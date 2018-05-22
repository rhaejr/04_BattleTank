// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming, 
	Locked
};

// forward declaration
class UTankBarrel;  
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable)
	void Initialize(UTankTurret * TurretToSet, UTankBarrel * BarrelToSet);

	void SetBarrelReferance(UTankBarrel* BarrelToSet);
	void SetTurretReferance(UTankTurret* TurretToSet);

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable)
	void Fire();

	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Locked;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, CAtegory = "Firing")
	float LaunchSpeed = 6000.0; // TODO find sensible default
	
	
	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, CAtegory = "Firing")
	float ReloadTimeInSeconds = 3;


	float LastFireTime = 0;

	FVector AimDirection = FVector(0);
};
