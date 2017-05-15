#pragma once

class UE4VOXELTERRAIN_API FEggPlayer
{
public:

	FEggPlayer(int32 InId);

	int32 GetId() {
		return Id;
	};




private:
	int32 Id;

};

