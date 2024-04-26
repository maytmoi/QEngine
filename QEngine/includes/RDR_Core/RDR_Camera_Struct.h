#pragma once

#include <chrono>

#include <vec2.hpp>
#include <vec3.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx\euler_angles.hpp>
#include <gtx\string_cast.hpp>

#include "RDR_Core\RDR_Ray_Struct.h"
#include "QE_Core\QE_IConfigurable_Struct.h"
#include "QE_Core\QE_Logger_Manager.h"

namespace RDR
{
	class Camera : public QE::IConfigurable
	{
		typedef unsigned int uint;
	public:

		glm::vec3* Render()
		{
			std::chrono::steady_clock::time_point wStartTime = std::chrono::high_resolution_clock::now();

			for (uint Y = 0; Y < mScreenDim.y; Y++)
			{
				for (uint X = 0; X < mScreenDim.x; X++)
				{
					float wXDir = glm::tan(mHFOV / 2.0f) * ((2.0f * X / mScreenDim.x) - 1.0f);
					float wYDir = glm::tan(mVFOV / 2.0f) * ((2.0f * Y / mScreenDim.y) - 1.0f);

					glm::vec3 wRayDir(glm::yawPitchRoll(mYaw, mPitch, mRoll) * glm::vec4(wXDir, wYDir, 1, 1));

					Ray wRay(mOrigin, wRayDir, 8);

					glm::vec3 wPixel((float)X / mScreenDim.x, (float)Y / mScreenDim.y, 1);

					mRendered[X + Y * mScreenDim.x] = wPixel;
				}
			}
			std::chrono::steady_clock::time_point wEndTime = std::chrono::high_resolution_clock::now();
			std::chrono::milliseconds wDuration = std::chrono::duration_cast<std::chrono::milliseconds>(wEndTime - wStartTime);

			LOG_DEBUG("Scene rendered, duration: " << wDuration);
			return mRendered;
		}

		virtual void UpdateParameters() override
		{
			mHFOV = 2 * glm::atan((glm::tan(mVFOV / 2) * mScreenDim.x) / mScreenDim.y);
			LOG_WARN("Temporary implementation, must be removed");
		}

	public:

		Camera() = delete;
		Camera(const Camera&) = default;
		Camera(glm::vec3 iOrigin, float iYaw, float iPitch, float iRoll, float iVFOV, glm::vec2 iScreenDim) :
			mOrigin(iOrigin),
			mDirection(0, 0, 0),
			mYaw(iYaw),
			mPitch(iPitch),
			mRoll(iRoll),
			mVFOV(iVFOV),
			mHFOV(0),
			mScreenDim(iScreenDim)
		{
			UpdateParameters();
			mRendered = new glm::vec3[mScreenDim.x * mScreenDim.y];
		}
		~Camera() = default;

	private:

		glm::vec3 mOrigin;		// Origin of the Camera
		glm::vec3 mDirection;	// Direction of the Camera

		float mYaw;				// Yaw angle of the Camera
		float mPitch;			// Pitch angle of the Camera
		float mRoll;			// Roll angle of the Camera

		float mVFOV;			// Vertical FOV angle of the Camera (in rad)
		float mHFOV;			// Horizontal FOV angle of the Camera (in rad)

		glm::uvec2 mScreenDim;	// Screen Dimension


		glm::vec3* mRendered;
	};
}