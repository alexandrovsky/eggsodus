#include "UE4VoxelTerrain.h"
#include "EggRepositoryImpl.h"

FEggRepositoryImpl::FEggRepositoryImpl()
{

}

TArray<UEgg*> FEggRepositoryImpl::FindEggsByPlayerId(int32 PlayerId)
{
	TArray<UEgg*> Results;
	for (UEgg* egg : Eggs)
		if (egg->GetPlayerId() == PlayerId)
			Results.Add(egg);
	return Results;

}

void FEggRepositoryImpl::Initialize() {

}


void FEggRepositoryImpl::AddEgg(UEgg& InEgg) {
	bool contains = false;
	for (UEgg* Egg : Eggs)
		if (Egg->GetEggId() == InEgg.GetEggId()) {
			contains = true;
			break;
		}
	if (!contains)
		Eggs.Add(&InEgg);
	UE_LOG(LogTemp, Warning, TEXT("Eggs : %i"), Eggs.Num());
}
void FEggRepositoryImpl::ShutDown() {

	for (UEgg* Egg : Eggs)
		Egg->Destroy();

	Eggs.Empty();
}