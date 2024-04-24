#pragma once
#include <vec3.hpp>

#include "QE_Core\QE_Voxel_Struct.h"
#include "QE_Core\QE_Logger_Manager.h"

class Chunk
{
	typedef unsigned int uint;
public:
	inline Voxel GetVoxelAt(glm::ivec3 iPos)
	{
		ASSERT_ERROR(0 <= iPos.x && iPos.x < 16, "X Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iPos.y && iPos.y < 16, "Y Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iPos.z && iPos.z < 16, "Z Value is not in defined bound, 0 to 15");

		return mChunk[iPos.x + 16 * iPos.y + 16 * 16 * iPos.z];
	}
	inline Voxel GetVoxelAt(uint iX, uint iY, uint iZ)
	{
		ASSERT_ERROR(0 <= iX && iX < 16, "X Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iY && iY < 16, "Y Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iZ && iZ < 16, "Z Value is not in defined bound, 0 to 15");

		return mChunk[iX + 16 * iY + 16 * 16 * iZ];
	}

	inline void SetVoxelAt(glm::ivec3 iPos, Voxel iVoxel)
	{
		ASSERT_ERROR(0 <= iPos.x && iPos.x < 16, "X Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iPos.y && iPos.y < 16, "Y Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iPos.z && iPos.z < 16, "Z Value is not in defined bound, 0 to 15");

		mChunk[iPos.x + 16 * iPos.y + 16 * 16 * iPos.z] = iVoxel;
	}
	inline void SetVoxelAt(uint iX, uint iY, uint iZ, Voxel iVoxel)
	{
		ASSERT_ERROR(0 <= iX && iX < 16, "X Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iY && iY < 16, "Y Value is not in defined bound, 0 to 15");
		ASSERT_ERROR(0 <= iZ && iZ < 16, "Z Value is not in defined bound, 0 to 15");

		mChunk[iX + 16 * iY + 16 * 16 * iZ] = iVoxel;
	}

private:
	Voxel mChunk[16 * 16 * 16];
};