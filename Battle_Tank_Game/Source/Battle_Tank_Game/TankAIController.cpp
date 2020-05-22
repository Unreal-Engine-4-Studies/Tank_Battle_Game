// Leonardo Cruz copyright


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ContorlledTank = GetControlledTank();
	if (!ContorlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank AI Controller has no possessed tank!"));
	}
	else
	{
		// Tank AI Controller possessing a tank
	}

	PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("There is no player controller!"));
	}
	else
	{
		// There is a player controller
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}