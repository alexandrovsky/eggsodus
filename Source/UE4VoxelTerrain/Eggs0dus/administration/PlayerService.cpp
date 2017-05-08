#include "UE4VoxelTerrain.h"
#include "PlayerService.h"

FPlayerService::FPlayerService()
{
	
}

void FPlayerService::Initialize(FEggRepository& InEggRepository, FPlayerRepository& InPlayerRepository)
{
    PlayerRepo = &InPlayerRepository;
	EggRepo = &InEggRepository;
    PlayerRepo->Initialize();
    EggRepo->Initialize();
}

void FPlayerService::UpdateTeam(float DeltaSeconds)
{
	FEggPlayer& CurrentPlayer = PlayerRepo->FindCurrentPlayer();
	UEgg& CurrentEgg = EggRepo->FindEggsByPlayerId(CurrentPlayer.GetId());
	CurrentEgg.UpdatePosition(FVector::ZeroVector, DeltaSeconds);
}

void FPlayerService::CreateTeam(int32 TeamId, int32 NumEggs)
{
	FEggPlayer* PlayerComponent = new FEggPlayer();

}
