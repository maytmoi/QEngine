#include <iostream>
#include <thread>
#include <chrono>

#include "QE_Core\QE_Engine_Process.h"
#include "QE_Core\QE_Logger_Manager.h"

int main()
{
	LOG_INFO("Main thread entrypoint entered, ID: " << std::this_thread::get_id());
	QE::EngineProcess::GetProcess();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	return 0;
}