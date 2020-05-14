// Leonardo Cruz copyright


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ContorlledTank = GetControlledTank();
	if (!ContorlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank Player Controller has no possessed tank!"));		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller possessing %s"), *ContorlledTank->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());
}