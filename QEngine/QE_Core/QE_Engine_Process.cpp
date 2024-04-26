#include <thread>

#include "QE_Core\QE_Engine_Process.h"
#include "QE_Core\QE_Logger_Manager.h"

#include "RDR_Core\RDR_Renderer_Process.h"

namespace QE
{
	int EngineProcess::Entrypoint()
	{
		RDR::RendererProcess::GetProcess();
		return 0;
	}
}