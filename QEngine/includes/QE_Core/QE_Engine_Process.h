#pragma once
#include "QE_Core\QE_IProcess.h"

namespace QE
{
	class EngineProcess :
		public IProcess<EngineProcess>
	{
		friend class IProcess<EngineProcess>;
	public:

	protected:
		EngineProcess() : IProcess<EngineProcess>(std::string("Engine")) { }
		EngineProcess(const EngineProcess&) = delete;
		EngineProcess operator=(const EngineProcess&) = delete;
		~EngineProcess() = default;

	private:
		virtual void Entrypoint() override;
	};
}