#include <iostream>
#include <thread>
#include <chrono>

#include "QE_Core\QE_Engine_Process.h"
#include "QE_Core\QE_Logger_Manager.h"

int main()
{
	LOG_INFO("Main thread entrypoint entered, ID: " << std::this_thread::get_id());
	QE::EngineProcess::GetProcess();
	std::cin.get();
	return 0;
}