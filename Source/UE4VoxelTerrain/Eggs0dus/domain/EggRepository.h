#pragma once


#include "Eggs0dus/domain/Egg.h"


class UE4VOXELTERRAIN_API FEggRepository
{
public:

	virtual TArray<UEgg*> FindEggsByPlayerId(int32 PlayerId) = 0;
	virtual void AddEgg(UEgg& InEgg) = 0;
	virtual void Initialize() = 0;
	virtual void ShutDown() = 0;

};

