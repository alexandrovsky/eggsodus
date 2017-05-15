
#pragma once

#include "Eggs0dus/domain/PlayerRepository.h"
#include "Eggs0dus/domain/EggRepository.h"


class UE4VOXELTERRAIN_API FPlayerService
{
public:

	FPlayerService();
	virtual ~FPlayerService() { };

	virtual void Initialize(int32 InTeamId, FEggRepository* EggRepository, FPlayerRepository* PlayerRepository, USkeletalMesh* InSkeletalMesh);
	
	virtual void UpdateTeam(float DeltaSeconds);
	
	virtual void CreateTeam(int32 TeamId, int32 NumEggs);

	virtual void AddPlayer(FEggPlayer& InEggPlayer);

private:

	FPlayerRepository* PlayerRepo;
	FEggRepository* EggRepo;

};

