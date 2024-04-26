#pragma once
#include <vec3.hpp>

#include "QE_Core\QE_Voxel_Struct.h"
#include "QE_Core\QE_Logger_Manager.h"

namespace QE
{
	class Chunk
	{
		typedef unsigned int uint;
	public:
		inline Voxel GetVoxelAt(glm::uvec3 iPos)
		{
			ASSERT_ERROR(0 <= iPos.x && iPos.x < 16, "X Value is not in defined bound, 0 to 15, value: " << iPos.x);
			ASSERT_ERROR(0 <= iPos.y && iPos.y < 16, "Y Value is not in defined bound, 0 to 15, value: " << iPos.y);
			ASSERT_ERROR(0 <= iPos.z && iPos.z < 16, "Z Value is not in defined bound, 0 to 15, value: " << iPos.z);

			return mChunk[iPos.x + 16 * iPos.y + 16 * 16 * iPos.z];
		}
		inline Voxel GetVoxelAt(uint iX, uint iY, uint iZ)
		{
			ASSERT_ERROR(0 <= iX && iX < 16, "X Value is not in defined bound, 0 to 15, value: " << iX);
			ASSERT_ERROR(0 <= iY && iY < 16, "Y Value is not in defined bound, 0 to 15, value: " << iY);
			ASSERT_ERROR(0 <= iZ && iZ < 16, "Z Value is not in defined bound, 0 to 15, value: " << iZ);

			return mChunk[iX + 16 * iY + 16 * 16 * iZ];
		}

		inline void SetVoxelAt(glm::uvec3 iPos, Voxel iVoxel)
		{
			ASSERT_ERROR(0 <= iPos.x && iPos.x < 16, "X Value is not in defined bound, 0 to 15, value: " << iPos.x);
			ASSERT_ERROR(0 <= iPos.y && iPos.y < 16, "Y Value is not in defined bound, 0 to 15, value: " << iPos.y);
			ASSERT_ERROR(0 <= iPos.z && iPos.z < 16, "Z Value is not in defined bound, 0 to 15, value: " << iPos.z);

			mChunk[iPos.x + 16 * iPos.y + 16 * 16 * iPos.z] = iVoxel;
		}
		inline void SetVoxelAt(uint iX, uint iY, uint iZ, Voxel iVoxel)
		{
			ASSERT_ERROR(0 <= iX && iX < 16, "X Value is not in defined bound, 0 to 15, value: " << iX);
			ASSERT_ERROR(0 <= iY && iY < 16, "Y Value is not in defined bound, 0 to 15, value: " << iY);
			ASSERT_ERROR(0 <= iZ && iZ < 16, "Z Value is not in defined bound, 0 to 15, value: " << iZ);

			mChunk[iX + 16 * iY + 16 * 16 * iZ] = iVoxel;
		}

	public:

		Chunk() = default;
		Chunk(const Chunk&) = default;
		~Chunk() = default;

	private:
		Voxel mChunk[16 * 16 * 16];
	};
}