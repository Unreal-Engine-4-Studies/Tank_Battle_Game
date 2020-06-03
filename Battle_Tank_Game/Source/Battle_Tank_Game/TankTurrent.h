// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_GAME_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSeconds = 35.f;
};
