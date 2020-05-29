// Leonardo Cruz copyright

#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName ("Aiming Component"));
}

void ATank::AimAt(FVector LocationToHit)
{
	TankAimingComponent->AimAt(LocationToHit, LaunchSpeed);
}

void ATank::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelRef(BarrelToSet);
}

