#pragma once

#include "QE_Core\QE_Logger_Manager.h"

#define pi 3.141592653585

class Material
{
public:
	inline float GetReflectionHue()
	{
		ASSERT_WARN(0 <= mReflectionHue && mReflectionHue <= 2 * pi, "Reflection Hue Value is not in defined bound, 0 to 2pi");
		return mReflectionHue;
	}

	inline float GetRefractionHue()
	{
		ASSERT_WARN(0 <= mRefractionHue && mRefractionHue <= 2 * pi, "Refraction Hue Value is not in defined bound, 0 to 2pi");
		return mRefractionHue;
	}

	inline float GetReflectionProp()
	{
		ASSERT_ERROR(0 <= mReflectRefractProp && mReflectRefractProp <= 1, "Reflection Proportion Value is not in defined bound, 0 to 1");
		return mReflectRefractProp;
	}

	inline float GetRefractionProp()
	{
		ASSERT_ERROR(0 <= mReflectRefractProp && mReflectRefractProp <= 1, "Refraction Proportion Value is not in defined bound, 0 to 1");
		return 1 - mReflectRefractProp;
	}

	inline float GetSpecularProp()
	{
		ASSERT_ERROR(0 <= mReflectProp && mReflectProp <= 1, "Specular Proportion Value is not in defined bound, 0 to 1");
		return mReflectProp;
	}

	inline float GetDiffusionProp()
	{
		ASSERT_ERROR(0 <= mReflectProp && mReflectProp <= 1, "Diffusion Proportion Value is not in defined bound, 0 to 1");
		return 1 - mReflectProp;
	}

	inline float GetClarityProp()
	{
		ASSERT_ERROR(0 <= mRefractProp && mRefractProp <= 1, "Clarity Proportion Value is not in defined bound, 0 to 1");
		return mRefractProp;
	}

	inline float GetDispersionProp()
	{
		ASSERT_ERROR(0 <= mRefractProp && mRefractProp <= 1, "Dispersion Proportion Value is not in defined bound, 0 to 1");
		return 1 - mRefractProp;
	}

	inline float GetRefractionIndex()
	{
		ASSERT_ERROR(1 <= mRefractionIndex, "Refraction Index Value is not in defined bound, 1 to inf");
		return mRefractionIndex;
	}

private:
	float mReflectionHue;		// 0 to 2pi, red to green to blue to red
	float mRefractionHue;		// 0 to 2pi, red to green to blue to red

	float mReflectRefractProp;	// 0 to 1, 100% refraction to 100% reflection

	float mReflectProp;			// 0 to 1, 100% diffused to 100% specular
	float mRefractProp;			// 0 to 1, 100% dispersed to 100% clarity

	float mRefractionIndex;		// 1 to inf, min to max
};