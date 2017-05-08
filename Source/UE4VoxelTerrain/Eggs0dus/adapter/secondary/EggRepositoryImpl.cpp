#include "UE4VoxelTerrain.h"
#include "EggRepositoryImpl.h"

FEggRepositoryImpl::FEggRepositoryImpl()
{

}

UEgg& FEggRepositoryImpl::FindEggsByPlayerId(int32 PlayerId)
{
	return *new UEgg();
}

void FEggRepositoryImpl::Initialize() {

}