// Copyright blackw 2015-2020

#pragma once

#include "EngineMinimal.h"
#include "ProcMeshData.h"

#include "Components/MeshComponent.h"
#include "SandboxVoxeldata.h"

#include "SandboxTerrainMeshComponent.generated.h"


/**
*
*/
UCLASS()
class UNREALSANDBOXTERRAIN_API USandboxTerrainMeshComponent : public UMeshComponent
{
	GENERATED_UCLASS_BODY()

public:

	void SetMeshData(TMeshDataPtr mdPtr);

	void SetLodFlag(bool bLodFlag) {
		this->bLodFlag = bLodFlag;
	}

	//~ Begin UPrimitiveComponent Interface.
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual class UBodySetup* GetBodySetup() override;
	//~ End UPrimitiveComponent Interface.

	//~ Begin UMeshComponent Interface.
	virtual int32 GetNumMaterials() const override;
	//~ End UMeshComponent Interface.

	//~ Begin UObject Interface
	virtual void PostLoad() override;
	//~ End UObject Interface.

	bool bLodFlag;

	virtual void GetUsedMaterials(TArray<UMaterialInterface*>& OutMaterials, bool bGetDebugMaterials = false) const override;

private:

	TMeshDataPtr MeshDataPtr;

	//~ Begin USceneComponent Interface.
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
	//~ Begin USceneComponent Interface.

	void UpdateLocalBounds();

	/** Array of sections of mesh */
	TArray<TMeshLodSection> MeshSectionLodArray;

	/** Local space bounds of mesh */
	UPROPERTY()
	FBoxSphereBounds LocalBounds;

	TArray<UMaterialInterface*> LocalMaterials;

	friend class FProceduralMeshSceneProxy;

};