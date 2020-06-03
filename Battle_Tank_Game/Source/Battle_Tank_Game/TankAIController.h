// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLE_TANK_GAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	void AimAtPlayer();

private:
	ATank* ControlledTank;
	ATank* PlayerTank;
};
