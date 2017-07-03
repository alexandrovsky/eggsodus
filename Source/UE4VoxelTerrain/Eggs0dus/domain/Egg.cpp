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

	FVector InitPosition = FMath::RandPointInBox(FBox(FVector(-100.0f, -100.0f, 400.0f), FVector(100.0f, 100.0f, 400.0f)));
	SetRelativeLocation(InitPosition);
	SetWorldLocation(InitPosition);

	UE_LOG(LogTemp, Warning, TEXT("[ UEgg : TID %i , EID %i , Pos %s ] [ Initialize ] - Begin"), InPlayerId, InEggId, *(GetComponentLocation().ToString()));

	SetSkeletalMesh(InSkeletalMesh);
}

void UEgg::UpdatePosition(const FVector& Velocity, float InDeltaSeconds)
{
	Position += Velocity*InDeltaSeconds;
	SetWorldLocation(Position);
}
