// Leonardo Cruz copyright

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class BATTLE_TANK_GAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AimAt(FVector ObjHit);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRef(UStaticMeshComponent* BarrelToSet);

protected:
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f;
};
