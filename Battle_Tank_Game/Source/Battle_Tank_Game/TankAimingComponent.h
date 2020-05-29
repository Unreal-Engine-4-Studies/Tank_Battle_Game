// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

// Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_GAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTankAimingComponent();
	void AimAt(FVector ObjHit, float LaunchSpeed);
	void SetBarrelRef(UTankBarrel* BarrelToSet);

private:	
	FVector OutLaunchVelocity;
	FVector AimDirection;
	FRotator BarrelRotator;
	FRotator AimAsRotator;
	FRotator DeltaRotator;
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirct);
};
