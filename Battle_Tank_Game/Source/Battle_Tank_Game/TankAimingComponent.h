// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurrent;

// Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_GAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTankAimingComponent();
	void AimAt(FVector LocationToHit, float LaunchSpeed);
	void SetBarrelRef(UTankBarrel* BarrelToSet);
	void SetTurrentRef(UTankTurrent* TurrentToSet);

private:	
	FVector OutLaunchVelocity;
	FRotator BarrelRotator;
	FRotator TurrentRotator;
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;

	void MoveBarrelTowards(FVector AimDirct);
};
