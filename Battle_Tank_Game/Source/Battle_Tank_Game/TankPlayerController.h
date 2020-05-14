// Leonardo Cruz copyright

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
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

private:	
	ATank* ControlledTank;
	FVector TankLoc;
	FRotator TankRot;	
	FVector LineTraceEnd;
	FVector ObjHit;

	UPROPERTY(EditAnywhere)
	float XCrossHairLoc = 0.5f;
	UPROPERTY(EditAnywhere)
	float YCrosshairLoc = 0.33333f;
	UPROPERTY(EditAnywhere)
	float Reach = 120.f;
};
