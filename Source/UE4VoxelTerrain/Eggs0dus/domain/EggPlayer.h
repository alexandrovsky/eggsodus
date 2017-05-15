#pragma once

class UE4VOXELTERRAIN_API FEggPlayer
{
public:

	FEggPlayer(int32 InId);
	virtual ~FEggPlayer();

	int32 GetId() {
		return Id;
	};




private:
	int32 Id;

};

