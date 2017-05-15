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
}

void ATeam::Initialize()
{
	for (TActorIterator<ATeam> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		if ((*ActorItr)->GetFPlayerService() != nullptr) {
			PlayerService = (*ActorItr)->GetFPlayerService();
			break;
		}
	if (PlayerService == nullptr) {
		PlayerService = new FPlayerService();
		PlayerService->Initialize(TeamId, new FEggRepositoryImpl(), new FPlayerRepositoryImpl(), StatMesh);
	}
	else {
		PlayerService->CreateTeam(TeamId, 3);
	}
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