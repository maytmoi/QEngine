#pragma once

#include <string>
#include <thread>
#include <chrono>

#include "QE_Core\QE_Logger_Manager.h"

namespace QE
{
	template <class Derived>
	class IProcess
	{
	public:

		static Derived& GetProcess()
		{
			static Derived wInstance;
			return wInstance;
		}

		std::string GetProcessName()
		{
			return mName;
		}

	protected:

		virtual void Entrypoint() = 0;

	protected:

		IProcess(std::string iName) :
			mName(iName),
			mDuration(std::chrono::milliseconds(0)),
			mThread(std::thread(&Derived::ThreadEntrypoint, static_cast<Derived*>(this))){ }
		
		IProcess() = delete;
		virtual ~IProcess()
		{
			if (mThread.joinable())
			{
				mThread.join();
				LOG_INFO(Derived::GetProcess().GetProcessName() << " Process is terminated successfully, duration :" << mDuration);
			}
			else
			{
				LOG_WARN(Derived::GetProcess().GetProcessName() << " Process is not joinable at the destruction of the process");
			}
		}

	private:
		void ThreadEntrypoint()
		{
			LOG_INFO(Derived::GetProcess().GetProcessName() << " Process entrypoint entered, ID : " << std::this_thread::get_id());
			std::chrono::steady_clock::time_point wStartTime = std::chrono::high_resolution_clock::now();
			
			Entrypoint();

			std::chrono::steady_clock::time_point wEndTime = std::chrono::high_resolution_clock::now();
			mDuration = std::chrono::duration_cast<std::chrono::milliseconds>(wEndTime - wStartTime);
		}

	protected:
		std::string mName;
		std::chrono::milliseconds mDuration;
		std::thread mThread;
	};
}
