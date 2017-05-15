#include "UE4VoxelTerrain.h"
#include "Egg.h"

UEgg::UEgg()
{
}


UEgg::~UEgg()
{

}
void UEgg::Initialize(int32 InPlayerId, USkeletalMesh* InSkeletalMesh)
{
	PlayerId = InPlayerId;

	SetMobility(EComponentMobility::Movable);
	this->SetWorldScale3D(FVector(1, 1, 1));

	//set position
	FVector InitPosition = FMath::RandPointInBox(FBox(FVector(-100.0f, -100.0f, -10.0f), FVector(100.0f, 100.0f, 10.0f)));
	SetRelativeLocation(InitPosition);
	Position = GetComponentLocation();
	SetSkeletalMesh(InSkeletalMesh);
}

void UEgg::UpdatePosition(const FVector& Velocity, float InDeltaSeconds)
{
	Position += Velocity*InDeltaSeconds;
	SetWorldLocation(Position);
}
