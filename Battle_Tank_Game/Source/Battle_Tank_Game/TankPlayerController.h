// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLE_TANK_GAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLoc(FVector& OutHitLocation) const;
	bool GetLookVectorHitLoc(FVector LookDirection, FVector& OutHitLocation) const;

private:	
	ATank* ControlledTank;
	FVector LocationToHit;

	UPROPERTY(EditAnywhere)
	float XCrossHairLoc = 0.5f;
	UPROPERTY(EditAnywhere)
	float YCrosshairLoc = 0.3f;
	UPROPERTY(EditAnywhere)
	float Reach = 1000000.f;
};
