#include "UE4VoxelTerrain.h"
#include "PlayerService.h"

FPlayerService::FPlayerService()
{
	
}

void FPlayerService::Initialize(int32 InTeamId, FEggRepository* InEggRepository, FPlayerRepository* InPlayerRepository, USkeletalMesh* InSkeletalMesh)
{
	if (PlayerRepo == nullptr)
		PlayerRepo = InPlayerRepository;
	else
		delete InPlayerRepository;
	if (EggRepo == nullptr)
		EggRepo = InEggRepository;
	else
		delete InEggRepository;
    PlayerRepo->Initialize();
    EggRepo->Initialize();
	PlayerRepo->AddPlayer(*new FEggPlayer(InTeamId));
	for (int i = 0; i < 3; i++) {
		UEgg* Egg = new UEgg();
		Egg->Initialize(InTeamId, InSkeletalMesh);
		EggRepo->AddEgg(*Egg);
	}


}

void FPlayerService::UpdateTeam(float DeltaSeconds)
{
	FEggPlayer& CurrentPlayer = PlayerRepo->FindCurrentPlayer();
	TArray<UEgg&> Eggs = EggRepo->FindEggsByPlayerId(CurrentPlayer.GetId());
	Eggs[0].UpdatePosition(FVector(1, 0, 0) , DeltaSeconds);
}

void FPlayerService::CreateTeam(int32 TeamId, int32 NumEggs)
{
	FEggPlayer* PlayerComponent = new FEggPlayer(TeamId);

}
