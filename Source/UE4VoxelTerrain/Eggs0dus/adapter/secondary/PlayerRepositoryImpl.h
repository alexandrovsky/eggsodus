#pragma once

#include "Eggs0dus/domain/PlayerRepository.h"
#include "Eggs0dus/domain/EggPlayer.h"


class UE4VOXELTERRAIN_API FPlayerRepositoryImpl : public FPlayerRepository
{
public:

	FPlayerRepositoryImpl();
	virtual ~FPlayerRepositoryImpl() { };
	virtual void Initialize();

	FEggPlayer& FindCurrentPlayer() override;

};

