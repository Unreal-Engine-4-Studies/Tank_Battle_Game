// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLE_TANK_GAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	void AimAt(FVector LocationToHit);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRef(UTankBarrel* BarrelToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f;
};
