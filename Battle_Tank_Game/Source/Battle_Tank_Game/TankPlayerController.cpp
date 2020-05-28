// Leonardo Cruz copyright

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank Player Controller has no possessed tank!"));		
	}
	else
	{
		// Tank Player Controller has possessed a tank
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ControlledTank) { return; }

	if (GetSightRayHitLoc(ObjHit))
	{
		ControlledTank->AimAt(ObjHit);
	}
}

bool ATankPlayerController::GetSightRayHitLoc(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	FVector LookDirection, WorldLoc;
	FVector2D ScreenLoc;

	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	ScreenLoc = FVector2D(XCrossHairLoc * ViewportSizeX, YCrosshairLoc * ViewportSizeY);	
	if (DeprojectScreenPositionToWorld(ScreenLoc.X, ScreenLoc.Y, OUT WorldLoc, OUT LookDirection))
	{
		GetLookVectorHitLoc(LookDirection, OutHitLocation);
	}
	return true;	
}

bool ATankPlayerController::GetLookVectorHitLoc(FVector LookDirection, FVector& OutHitLocation) const
{
	FVector StartLoc, LineTraceEnd;
	FHitResult OutObjHit;

	StartLoc = PlayerCameraManager->GetCameraLocation();
	LineTraceEnd = StartLoc + LookDirection * Reach; // Set the Line trace end of the pawn.
	if (GetWorld()->LineTraceSingleByChannel(OUT OutObjHit, StartLoc, LineTraceEnd, ECollisionChannel::ECC_Visibility)) // Set the pawn reach and output what it is reaching.
	{
		OutHitLocation = OutObjHit.Location;
		return true;
	}
	else
	{
		OutHitLocation = FVector(0);
		return false;
	}
}
