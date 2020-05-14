// Leonardo Cruz copyright

#include "TankPlayerController.h"
#include "DrawDebugHelpers.h"


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
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller possessing %s"), *ControlledTank->GetName());
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
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *ObjHit.ToString()); 
	}
}

bool ATankPlayerController::GetSightRayHitLoc(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLoc = FVector2D(XCrossHairLoc * ViewportSizeX, YCrosshairLoc * ViewportSizeY);
	
	
	//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT TankLoc, OUT TankRot); // Set the loc and rot of the pawn/player.
	//LineTraceEnd = TankLoc + TankRot.Vector() * Reach; // Set the Line trace end of the pawn.
	//DrawDebugLine(GetWorld(), TankLoc, LineTraceEnd, FColor(100, 155, 200), false, 0.f, 0, 2.f);	// Draw debug line in editor.

	//FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetPawn()); // Set the parameters to ignore.
	//GetWorld()->LineTraceSingleByObjectType(OUT ObjHit, TankLoc, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters); // Set the pawn reach and output what it is reaching.	
	return false;
}