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
	void Initialize(USkeletalMesh* InSkeletalMesh);
	void UpdatePosition(const FVector& Velocity, float InDeltaSeconds);
	void SetDirection(const FVector& InDirection) { Direction = InDirection; Direction.Normalize(); };
	void SetMesh(USkeletalMesh* InSkeletalMesh) { SkelMesh = InSkeletalMesh; SetSkeletalMesh(SkelMesh); };
private:
	UPROPERTY()
		FVector Position;
	UPROPERTY()
		FVector Direction;
	UPROPERTY()
		USkeletalMesh *SkelMesh;
};