#include "UE4VoxelTerrain.h"

#include "PlayerRepositoryImpl.h"

FPlayerRepositoryImpl::FPlayerRepositoryImpl()
{

}

FEggPlayer& FPlayerRepositoryImpl::FindCurrentPlayer()
{
	return *(Players[CurrentPlayer]);
}

bool FPlayerRepositoryImpl::PlayerExist(int32 PlayerId)
{
	for (FEggPlayer* Player : Players)
		if (Player->GetId() == PlayerId) 
			return true;
	return false;
}

void FPlayerRepositoryImpl::AddPlayer(FEggPlayer& InPlayer)
{
	bool contains = false;
	for (FEggPlayer* Player : Players)
		if (Player->GetId() == InPlayer.GetId()) {
			contains = true;
			break;
		}
	if (!contains)
		Players.Add(&InPlayer);
	UE_LOG(LogTemp, Warning, TEXT("Players : %i"), Players.Num());
}

void FPlayerRepositoryImpl::NextTurn()
{
	CurrentPlayer = (CurrentPlayer+1)%Players.Num();
}

void FPlayerRepositoryImpl::Initialize() {

}

void FPlayerRepositoryImpl::ShutDown() {
	Players.Empty();
}