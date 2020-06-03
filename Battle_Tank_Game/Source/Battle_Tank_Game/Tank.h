// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurrent;
class UTankAimingComponent;

UCLASS()
class BATTLE_TANK_GAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	void AimAt(FVector LocationToHit);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRef(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurrentRef(UTankTurrent* TurrentToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.f;
};
