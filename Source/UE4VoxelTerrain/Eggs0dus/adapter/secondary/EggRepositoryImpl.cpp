#include "UE4VoxelTerrain.h"
#include "EggRepositoryImpl.h"

FEggRepositoryImpl::FEggRepositoryImpl()
{

}

TArray<UEgg&> FEggRepositoryImpl::FindEggsByPlayerId(int32 PlayerId)
{
	TArray<UEgg&> Results;
	for (UEgg& egg : Eggs)
		if (egg.GetPlayerId() == PlayerId)
			Results.Add(egg);
	return Results;
}

void FEggRepositoryImpl::Initialize() {

}


void FEggRepositoryImpl::AddEgg(UEgg& InEgg) {
	Eggs.Add(InEgg);
}