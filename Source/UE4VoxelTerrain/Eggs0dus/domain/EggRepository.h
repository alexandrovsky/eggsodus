#pragma once


#include "Eggs0dus/domain/Egg.h"


class UE4VOXELTERRAIN_API FEggRepository
{
public:

	virtual UEgg& FindEggsByPlayerId(int32 PlayerId) = 0;
	virtual void Initialize() = 0;

};

