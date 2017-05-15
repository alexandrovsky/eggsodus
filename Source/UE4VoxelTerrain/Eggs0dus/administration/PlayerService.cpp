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

void FPlayerService::CreateTeam(int32 TeamId, int32 NumEggs)
{
	UE_LOG(LogTemp, Warning, TEXT("[ PlayerService ] [ CreateTeam ] - Begin"));
	PlayerRepo->AddPlayer(*new FEggPlayer(TeamId));

	for (int i = 0; i < 3; i++) {
		//UEgg* Egg = new UEgg();
		//Egg->Initialize(InTeamId, InSkeletalMesh);
		//EggRepo->AddEgg(*Egg);
	}
}
