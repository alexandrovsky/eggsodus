#pragma once


#include "Eggs0dus/domain/EggRepository.h"
#include "Eggs0dus/domain/Egg.h"


class UE4VOXELTERRAIN_API FEggRepositoryImpl : public FEggRepository
{
public:

	FEggRepositoryImpl();
	~FEggRepositoryImpl() { };
	void Initialize();

	UEgg& FindEggsByPlayerId(int32 PlayerId) override;

};

