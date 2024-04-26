#pragma once

#include "QE_Core\QE_IManager.h"

namespace QE
{
	class MemoryManager :
		public IManager<MemoryManager>
	{
		friend class IManager<MemoryManager>;

	public:
		

	protected:
		MemoryManager() = default;
		MemoryManager(const MemoryManager&) = delete;
		MemoryManager operator=(const MemoryManager&) = delete;
		~MemoryManager() = default;

	private:

		

	private:
		
	};
}