#include "UE4VoxelTerrain.h"

#include "Team.h"


ATeam::ATeam()
{
	UE_LOG(LogTemp, Warning, TEXT("[ Team ] [ ATeam ] - Begin"));
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TeamRoot"));
	RootComponent = RootSceneComponent;
	PrimaryActorTick.bCanEverTick = true;
}
ATeam::~ATeam()
{
	
}
void ATeam::OnConstruction(const FTransform& Transform)
{
	UE_LOG(LogTemp, Warning, TEXT("[ Team ] [ OnConstruction ] - Begin"));
	this->Initialize();
}

void ATeam::Initialize()
{
	if (contructed)
		return;
	contructed = true;
	UE_LOG(LogTemp, Warning, TEXT("[ Team : %i ] [ Initialize ] - Begin"), TeamId);
	for (TActorIterator<ATeam> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		if ((*ActorItr)->GetFPlayerService() != nullptr) {
			PlayerService = (*ActorItr)->GetFPlayerService();
			break;
		}
	if (PlayerService == nullptr) {
		PlayerService = new FPlayerService();
		PlayerService->Initialize( new FEggRepositoryImpl(), new FPlayerRepositoryImpl());
	}
	if (TeamId < 0) {
		TeamId = static_cast<int>(FMath::FRandRange(1.0f, 999.0f));
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
	UE_LOG(LogTemp, Warning, TEXT("[ Team ] [ BeginPlay ] - Begin"));
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