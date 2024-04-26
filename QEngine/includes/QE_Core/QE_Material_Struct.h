#pragma once

#include "QE_Core\QE_Logger_Manager.h"

#define pi 3.141592653585

namespace QE
{
	class Material
	{
	public:
		inline float GetReflectionHue()
		{
			ASSERT_WARN(0 <= mReflectionHue && mReflectionHue <= 2 * pi, "Reflection Hue Value is not in defined bound, 0 to 2pi, value: " << mReflectionHue);
			return mReflectionHue;
		}

		inline float GetRefractionHue()
		{
			ASSERT_WARN(0 <= mRefractionHue && mRefractionHue <= 2 * pi, "Refraction Hue Value is not in defined bound, 0 to 2pi, value: " << mRefractionHue);
			return mRefractionHue;
		}

		inline float GetReflectionProp()
		{
			ASSERT_ERROR(0 <= mReflectRefractProp && mReflectRefractProp <= 1, "Reflection Proportion Value is not in defined bound, 0 to 1, value: " << mReflectRefractProp);
			return mReflectRefractProp;
		}

		inline float GetRefractionProp()
		{
			ASSERT_ERROR(0 <= mReflectRefractProp && mReflectRefractProp <= 1, "Refraction Proportion Value is not in defined bound, 0 to 1, value: " << 1 - mReflectRefractProp);
			return 1 - mReflectRefractProp;
		}

		inline float GetSpecularProp()
		{
			ASSERT_ERROR(0 <= mReflectProp && mReflectProp <= 1, "Specular Proportion Value is not in defined bound, 0 to 1, value: " << mReflectProp);
			return mReflectProp;
		}

		inline float GetDiffusionProp()
		{
			ASSERT_ERROR(0 <= mReflectProp && mReflectProp <= 1, "Diffusion Proportion Value is not in defined bound, 0 to 1, value: " << 1 - mReflectProp);
			return 1 - mReflectProp;
		}

		inline float GetClarityProp()
		{
			ASSERT_ERROR(0 <= mRefractProp && mRefractProp <= 1, "Clarity Proportion Value is not in defined bound, 0 to 1, value: " << mRefractProp);
			return mRefractProp;
		}

		inline float GetDispersionProp()
		{
			ASSERT_ERROR(0 <= mRefractProp && mRefractProp <= 1, "Dispersion Proportion Value is not in defined bound, 0 to 1, value: " << 1 - mRefractProp);
			return 1 - mRefractProp;
		}

		inline float GetRefractionIndex()
		{
			ASSERT_ERROR(1 <= mRefractionIndex, "Refraction Index Value is not in defined bound, 1 to inf, value: " << mRefractionIndex);
			return mRefractionIndex;
		}

		inline float GetEmissivePower()
		{
			ASSERT_ERROR(0 <= mRefractionIndex, "Emissive Power Value is not in defined bound, 0 to inf, value: " << mEmissivePower);
			return mEmissivePower;
		}

	public:

		Material() = delete;
		Material(const Material&) = default;
		Material(float iReflectionHue, float iRefractionHue, float iReflectRefractProp, float iReflectProp, float iRefractProp, float iRefractionIndex, float iEmissivePower) :
			mReflectionHue(iReflectionHue),
			mRefractionHue(iRefractionHue),
			mReflectRefractProp(iReflectRefractProp),
			mReflectProp(iReflectProp),
			mRefractProp(iRefractProp),
			mRefractionIndex(iRefractionIndex),
			mEmissivePower(iEmissivePower)
		{ }
		~Material() = default;

	private:
		float mReflectionHue;		// 0 to 2pi, red to green to blue to red
		float mRefractionHue;		// 0 to 2pi, red to green to blue to red

		float mReflectRefractProp;	// 0 to 1, 100% refraction to 100% reflection

		float mReflectProp;			// 0 to 1, 100% diffused to 100% specular
		float mRefractProp;			// 0 to 1, 100% dispersed to 100% clarity

		float mRefractionIndex;		// 1 to inf, min to max

		float mEmissivePower;		// 0 to inf, not emmissive to blinding
	};
}