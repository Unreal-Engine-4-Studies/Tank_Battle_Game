// Leonardo Cruz copyright

#include "TankTurrent.h"

void UTankTurrent::Rotate(float RelativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Turrent Rotation: %f"), RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto Rotation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}