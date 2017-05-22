#pragma once



#include "Eggs0dus/domain/EggPlayer.h"

class UE4VOXELTERRAIN_API FPlayerRepository
{
public:
	
	virtual FEggPlayer& FindCurrentPlayer() = 0;
	virtual void Initialize() = 0;
	virtual void AddPlayer(FEggPlayer& InEggPlayer) = 0;
	virtual bool PlayerExist(int32 PlayerId) = 0;
	virtual void NextTurn() = 0;
	virtual void ShutDown() = 0;
};

