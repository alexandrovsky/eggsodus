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
}

void ATeam::Tick(float InDeltaSeconds)
{
	if (SkeletalMesh == nullptr)
	{
		return;
	}
	Super::Tick(InDeltaSeconds);
}
void ATeam::InitializeComponent()
{
	UE_LOG(LogTemp, Warning, TEXT("[ Team : %i ] [ InitializeComponent ] - Begin"), TeamId);
	for (TActorIterator<ATeam> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		if ((*ActorItr)->GetFPlayerService() != nullptr) {
			PlayerService = (*ActorItr)->GetFPlayerService();
			break;
		}
	if (PlayerService == nullptr) {
		PlayerService = new FPlayerService();
		PlayerService->Initialize(new FEggRepositoryImpl(), new FPlayerRepositoryImpl());
	}
	if (TeamId < 0 || !PlayerService->TeamExist(TeamId)) {
		TeamId = static_cast<int>(FMath::FRandRange(1.0f, 999.0f));
		UE_LOG(LogTemp, Warning, TEXT("[ Team : %i ] [ InitializeComponent ] - ID Created"), TeamId);
		TArray<UEgg*> Eggs;
		for (int i = 0; i < 3; i++) {
			UEgg* Egg = NewObject<UEgg>(this);
			Egg->RegisterComponent();
			Egg->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
			Eggs.Add(Egg);
		}
		PlayerService->CreateTeam(TeamId, Eggs, SkeletalMesh);
	}
}
void ATeam::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("[ Team : %i ] [ BeginPlay ] - Begin"), TeamId);
	Super::BeginPlay();
	InitializeComponent();
}
void ATeam::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Shutdown();
}
void ATeam::Shutdown()
{
	PlayerService->ShutDown();
	delete PlayerService;
	PlayerService = nullptr;
}