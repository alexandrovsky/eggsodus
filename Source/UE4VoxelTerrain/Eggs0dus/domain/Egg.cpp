#include "UE4VoxelTerrain.h"
#include "Egg.h"

UEgg::UEgg()
{
	SetMobility(EComponentMobility::Movable);
	Position = GetComponentLocation();
	Direction = GetComponentRotation().Vector();
	bGenerateOverlapEvents = true;
}

UEgg::~UEgg()
{
}


void UEgg::Initialize(int32 InPlayerId, int32 InEggId, USkeletalMesh* InSkeletalMesh)
{
	PlayerId = InPlayerId;
	EggId = InEggId;
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
