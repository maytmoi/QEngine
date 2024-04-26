#pragma once

#include <vec3.hpp>

#include "QE_Core\QE_Logger_Manager.h"

#define pi 3.141592653585f

namespace RDR
{
	class Ray
	{
		typedef unsigned int uint;
	public:


	public:

		Ray() = delete;
		Ray(const Ray&) = default;
		Ray(glm::vec3 iOrigin, glm::vec3 iDirection, uint iLevel) :
			mOrigin(iOrigin),
			mDirection(iDirection),
			mHue(4 * pi / 3),
			mPower(0),
			mLastRefractionIndex(1),
			mLevel(iLevel)
		{ }
		~Ray() = default;

	private:

		glm::vec3 mOrigin;		// Origin of the ray
		glm::vec3 mDirection;	// Direction of the ray

		float mHue;				// Hue of the ray
		float mPower;			// Power of the ray

		float mLastRefractionIndex;	// Last encounterd Refraction Index

		uint mLevel;			// Level of the ray, 0 to max, leaf to root
	};
}