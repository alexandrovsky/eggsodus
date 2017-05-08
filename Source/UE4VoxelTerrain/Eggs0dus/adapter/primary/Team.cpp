#include "UE4VoxelTerrain.h"

#include "Team.h"


ATeam::ATeam()
{
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TeamRoot"));
	RootComponent = RootSceneComponent;
	PrimaryActorTick.bCanEverTick = true;
}
ATeam::~ATeam()
{
	
}
void ATeam::OnConstruction(const FTransform& Transform)
{
	this->Initialize();
	int32 NumberOfTeams = 3;
	for (int32 i = 0; i < NumberOfTeams; ++i) {

	}

}

void ATeam::Initialize()
{
	PlayerService = new FPlayerService();
	PlayerService->Initialize(*new FEggRepositoryImpl(), *new FPlayerRepositoryImpl());
}
void ATeam::Tick(float InDeltaSeconds)
{
	if (StatMesh == nullptr)
	{
		return;
	}
	Super::Tick(InDeltaSeconds);
}
void ATeam::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}
void ATeam::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Shutdown();
}
void ATeam::Shutdown()
{
}