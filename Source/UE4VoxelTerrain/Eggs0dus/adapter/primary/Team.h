#pragma once

#include "Eggs0dus/administration/PlayerService.h"
#include "Eggs0dus/adapter/secondary/EggRepositoryImpl.h"
#include "Eggs0dus/adapter/secondary/PlayerRepositoryImpl.h"

//UE4 includes
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "Team.generated.h"

UCLASS()
class UE4VOXELTERRAIN_API ATeam : public AActor
{
	GENERATED_BODY()
public:
	ATeam();
	~ATeam();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void Initialize();
	virtual void BeginPlay() override;
	virtual void Shutdown();
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

private:

    FPlayerService* PlayerService;


	UPROPERTY()
		USceneComponent* RootSceneComponent;

	UPROPERTY(EditAnywhere)
		USkeletalMesh* StatMesh;
};