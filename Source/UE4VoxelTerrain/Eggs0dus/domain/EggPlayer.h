#pragma once

class UE4VOXELTERRAIN_API FEggPlayer
{
public:

	FEggPlayer();
	virtual ~FEggPlayer() {};

	int32 GetId() {
		return Id;
	};




private:
	int32 Id;

};

