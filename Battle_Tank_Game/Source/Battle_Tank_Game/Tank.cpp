// Leonardo Cruz copyright

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
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

void ATank::SetTurrentRef(UTankTurrent* TurrentToSet)
{
	TankAimingComponent->SetTurrentRef(TurrentToSet);
}

