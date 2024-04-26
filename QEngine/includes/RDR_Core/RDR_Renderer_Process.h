#pragma once
#include "QE_Core\QE_IProcess.h"

namespace RDR
{
	class RendererProcess :
		public QE::IProcess<RendererProcess>
	{
		friend class IProcess<RendererProcess>;

	private:
		virtual int Entrypoint() override;

	protected:
		RendererProcess() : IProcess<RendererProcess>(std::string("Renderer")) { }
		RendererProcess(const RendererProcess&) = delete;
		RendererProcess operator=(const RendererProcess&) = delete;
		~RendererProcess() = default;

	};
}
