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
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller possessing %s"), *ContorlledTank->GetName());
	}

	PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("There is no player controller!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller found %s"), *PlayerTank->GetName());
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