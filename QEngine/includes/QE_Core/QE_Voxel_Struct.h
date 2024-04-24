#pragma once

#include "QE_Core\QE_Material_Struct.h"

class Voxel
{
	typedef unsigned int uint;
public:
	inline uint GetObjectId() { return mObjectID; }
	inline void SetObjectId(uint iObjectID) { mObjectID = iObjectID; }

	inline Material GetMaterial() { return mMaterial; }
	inline void SetMaterial(Material iMaterial) { mMaterial = iMaterial; }

	inline float GetTemperature() { return mTemperature; }
	inline void SetTemperature(float iTemperature) { mTemperature = iTemperature; }

public:
	Voxel() = default;
	Voxel(const Voxel&) = default;
	~Voxel() = default;

private:
	uint mObjectID;		// Object owning that voxel
	Material mMaterial;	// Material
	float mTemperature; // Temperature
};