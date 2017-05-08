#pragma once



#include "Eggs0dus/domain/EggPlayer.h"

class UE4VOXELTERRAIN_API FPlayerRepository
{
public:
	
	virtual FEggPlayer& FindCurrentPlayer() = 0;
	virtual void Initialize() = 0;
};

