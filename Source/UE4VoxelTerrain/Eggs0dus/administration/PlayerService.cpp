#include "UE4VoxelTerrain.h"
#include "PlayerService.h"

FPlayerService::FPlayerService()
{
	PlayerRepo = nullptr;
	EggRepo = nullptr;
}

void FPlayerService::Initialize(FEggRepository* InEggRepository, FPlayerRepository* InPlayerRepository)
{
	UE_LOG(LogTemp, Warning, TEXT("[ PlayerService ] [ Initialize ] - Begin"));
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

}

void FPlayerService::UpdateTeam(float DeltaSeconds)
{
	FEggPlayer& CurrentPlayer = PlayerRepo->FindCurrentPlayer();
	//TArray<UEgg&> Eggs = EggRepo->FindEggsByPlayerId(CurrentPlayer.GetId());
	//Eggs[0].UpdatePosition(FVector(1, 0, 0) , DeltaSeconds);
}

void FPlayerService::CreateTeam(int32 TeamId, TArray<UEgg*> Eggs, USkeletalMesh* SkeletalMesh)
{
	UE_LOG(LogTemp, Warning, TEXT("[ PlayerService, TeamID: %i ] [ CreateTeam ] - Begin"), TeamId);
	if (PlayerRepo->PlayerExist(TeamId)) {
		UE_LOG(LogTemp, Warning, TEXT("[ PlayerService, TeamID: %i ] [ CreateTeam ] - Team Exists"), TeamId);
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[ PlayerService, TeamID: %i ] [ CreateTeam ] - Create new Team"), TeamId);
	PlayerRepo->AddPlayer(*new FEggPlayer(TeamId));
	int i = TeamId;
	for (UEgg* Egg : Eggs) {
		Egg->Initialize(TeamId, i++, SkeletalMesh);
		EggRepo->AddEgg(*Egg);
	}
}

bool FPlayerService::TeamExist(int32 TeamId)
{
	return PlayerRepo->PlayerExist(TeamId);
}

void FPlayerService::ShutDown()
{
	PlayerRepo->ShutDown();
	EggRepo->ShutDown();
	delete PlayerRepo;
	delete EggRepo;
}