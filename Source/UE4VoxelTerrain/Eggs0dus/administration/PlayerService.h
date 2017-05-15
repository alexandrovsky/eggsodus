
#pragma once

#include "Eggs0dus/domain/PlayerRepository.h"
#include "Eggs0dus/domain/EggRepository.h"


class UE4VOXELTERRAIN_API FPlayerService
{
public:

	FPlayerService();
	virtual ~FPlayerService() { };

	virtual void Initialize(FEggRepository* EggRepository, FPlayerRepository* PlayerRepository);
	
	virtual void UpdateTeam(float DeltaSeconds);
	
	virtual void CreateTeam(int32 TeamId, int32 NumEggs);


private:

	FPlayerRepository* PlayerRepo;
	FEggRepository* EggRepo;

};

