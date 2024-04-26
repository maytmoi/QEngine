#pragma once

#include "QE_Core\QE_Material_Struct.h"

namespace QE
{
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

		Voxel() = delete;
		Voxel(const Voxel&) = default;
		Voxel(Material iMaterial, float iTemperature, uint iLevel) :
			mObjectID(0),
			mMaterial(iMaterial),
			mTemperature(iTemperature),
			mLevel(iLevel)
		{ }
		~Voxel() = default;

	private:
		uint mObjectID;		// Object owning that voxel
		Material mMaterial;	// Material
		float mTemperature; // Temperature

		uint mLevel;		// Voxel level (size) in Octree, 0 to inf, leaf to root
	};
}