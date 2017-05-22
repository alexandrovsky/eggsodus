#pragma once
#include "Runtime/Core/Public/Math/Vector.h"
#include "Egg.generated.h"



UCLASS()
class UE4VOXELTERRAIN_API UEgg : public USkeletalMeshComponent
{
	GENERATED_BODY()
public:
	UEgg();
	~UEgg();
	void Initialize(int32 PlayerId, int32 EggId, USkeletalMesh* InSkeletalMesh);
	void UpdatePosition(const FVector& Velocity, float InDeltaSeconds);
	void SetDirection(const FVector& InDirection) { Direction = InDirection; Direction.Normalize(); };
	const int32 GetPlayerId() { return PlayerId; };
	const int32 GetEggId() { return EggId; };
	void Destroy() { this->DestroyComponent(); };
private:
	UPROPERTY()
		FVector Position;
	UPROPERTY()
		FVector Direction;
	int32 PlayerId;
	int32 EggId;
};