// Leonardo Cruz copyright

#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
#include "TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::AimAt(FVector LocationToHit, float LaunchSpeed)
{
	if (!Barrel) { return; }
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, Barrel->GetSocketLocation("BarrelNose"), LocationToHit, LaunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);		
	}
	else
	{
		// UE_LOG(LogTemp, Error, TEXT("No solution found at SuggestProjectileVelocity()!"));
	}	
}

void UTankAimingComponent::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurrentRef(UTankTurrent* TurrentToSet)
{
	if (!TurrentToSet) { return; }
	Turrent = TurrentToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirct)
{
	BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirct.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turrent->Rotate(DeltaRotator.Yaw);
}
