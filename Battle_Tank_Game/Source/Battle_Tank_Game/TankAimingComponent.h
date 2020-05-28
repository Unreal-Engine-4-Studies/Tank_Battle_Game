// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_GAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTankAimingComponent();
	void AimAt(FVector ObjHit, float LaunchSpeed);
	void SetBarrelRef(UStaticMeshComponent* BarrelToSet);

private:
	UStaticMeshComponent* Barrel = nullptr;
	FVector OutLaunchVelocity;
	FVector AimDirection;
	FRotator BarrelRotator;
	FRotator AimAsRotator;
	FRotator DeltaRotator;

	void MoveBarrelTowards(FVector AimDirct);
};
