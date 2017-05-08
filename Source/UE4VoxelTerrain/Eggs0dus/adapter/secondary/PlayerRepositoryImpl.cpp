#include "UE4VoxelTerrain.h"

#include "PlayerRepositoryImpl.h"

FPlayerRepositoryImpl::FPlayerRepositoryImpl()
{

}

FEggPlayer& FPlayerRepositoryImpl::FindCurrentPlayer()
{
	return *(new FEggPlayer());
}

void FPlayerRepositoryImpl::Initialize() {

}