#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <mutex>

#include "QE_Core\QE_IManager.h"


enum loggerLevelEnum
{
	eDebug = 0,
	eInfo  = 1,
	eWarn  = 2,
	eError = 3
};

namespace QE
{
	class LoggerManager :
		public IManager<LoggerManager>
	{
		friend class IManager<LoggerManager>;
		typedef unsigned int uint;

	public:
		void Log(const std::string& iMessage, const std::string& iFile, const std::string& iFunction, int iLine, loggerLevelEnum iLevel);

	protected:
		LoggerManager();
		LoggerManager(const LoggerManager&) = delete;
		LoggerManager operator=(const LoggerManager&) = delete;
		~LoggerManager();

	private:

		void LogCount();

	private:
		std::ofstream mLogFile;
		std::mutex mMutex;
		uint mLogCount[4] = {0,0,0,0};
	};
}

#define __FILENAME__ (strrchr("\\" __FILE__, '\\') + 1)

#define LOG(iMessage, iLevel){\
std::stringstream ss;\
ss << iMessage;\
QE::LoggerManager::GetManager().Log(ss.str(), __FILENAME__, __func__, __LINE__, iLevel);}

#define LOG_DEBUG(iMessage) LOG(iMessage, eDebug)
#define LOG_INFO(iMessage)  LOG(iMessage, eInfo )
#define LOG_WARN(iMessage)  LOG(iMessage, eWarn )
#define LOG_ERROR(iMessage) LOG(iMessage, eError)

#define ASSERT_DEBUG(iCondition, iMessage) if(!(iCondition)) {LOG_DEBUG(iMessage)}
#define ASSERT_INFO(iCondition, iMessage) if(!(iCondition))  {LOG_INFO(iMessage)}
#define ASSERT_WARN(iCondition, iMessage) if(!(iCondition))  {LOG_WARN(iMessage)}
#define ASSERT_ERROR(iCondition, iMessage) if(!(iCondition)) {LOG_ERROR(iMessage)}
