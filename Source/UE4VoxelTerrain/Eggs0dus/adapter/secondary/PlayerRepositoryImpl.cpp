#include "UE4VoxelTerrain.h"

#include "PlayerRepositoryImpl.h"

FPlayerRepositoryImpl::FPlayerRepositoryImpl()
{

}

FEggPlayer& FPlayerRepositoryImpl::FindCurrentPlayer()
{
	return Players[CurrentPlayer];
}

void FPlayerRepositoryImpl::AddPlayer(FEggPlayer& Player)
{
	Players.Add(Player);
}

void FPlayerRepositoryImpl::NextTurn()
{
	CurrentPlayer = (CurrentPlayer+1)%Players.Num();
}

void FPlayerRepositoryImpl::Initialize() {

}