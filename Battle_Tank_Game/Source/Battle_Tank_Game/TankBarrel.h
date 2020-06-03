// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLE_TANK_GAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);	

private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSeconds = 10.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegress = 35.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegress = 0.f;
};
