#include <thread>
#include <chrono>

#include "QE_Core\QE_Logger_Manager.h"

#include "RDR_Core\RDR_Renderer_Process.h"

namespace RDR
{
	void RendererProcess::Entrypoint()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}