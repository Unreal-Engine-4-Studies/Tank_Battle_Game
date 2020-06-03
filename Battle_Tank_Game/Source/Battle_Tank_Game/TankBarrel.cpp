// Leonardo Cruz copyright

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevation: %f"), RelativeSpeed);
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegress,MaxElevationDegress);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
