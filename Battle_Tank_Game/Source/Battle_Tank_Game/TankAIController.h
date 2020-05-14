// Leonardo Cruz copyright

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_GAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

private:
	ATank* ContorlledTank;
	ATank* PlayerTank;
};
