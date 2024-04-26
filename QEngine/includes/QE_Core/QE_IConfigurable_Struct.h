#pragma once

#include "QE_Core\QE_Logger_Manager.h"

namespace QE
{
	class IConfigurable
	{
	public:
		virtual void UpdateParameters() = 0;
	};
}