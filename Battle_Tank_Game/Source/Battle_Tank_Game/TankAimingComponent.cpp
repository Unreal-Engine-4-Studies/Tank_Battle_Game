// Leonardo Cruz copyright

#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector ObjHit, float LaunchSpeed)
{
	if (!Barrel) { return; }
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, Barrel->GetSocketLocation("BarrelNose"), ObjHit, LaunchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);		
	}
	else
	{
		// UE_LOG(LogTemp, Error, TEXT("No solution found at SuggestProjectileVelocity()!"));
	}
	
}

void UTankAimingComponent::SetBarrelRef(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirct)
{
	BarrelRotator = Barrel->GetForwardVector().Rotation();
	AimAsRotator = AimDirct.Rotation();
	DeltaRotator = AimAsRotator - BarrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetOwner()->GetName(), *DeltaRotator.ToString());
}