// Leonardo Cruz copyright

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector LocationToHit, float LaunchSpeed)
{
	if (!Barrel) { return; }
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, Barrel->GetSocketLocation("BarrelNose"), LocationToHit, LaunchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);		
	}
	else
	{
		// UE_LOG(LogTemp, Error, TEXT("No solution found at SuggestProjectileVelocity()!"));
	}
	
}

void UTankAimingComponent::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirct)
{
	BarrelRotator = Barrel->GetForwardVector().Rotation();
	AimAsRotator = AimDirct.Rotation();
	DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(5);	
}