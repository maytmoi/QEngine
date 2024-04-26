#include <string>
#include <iostream>
#include <iomanip>
#include <mutex>

#include "QE_Core\QE_Logger_Manager.h"

namespace QE
{
	void LoggerManager::Log(const std::string& iMessage, const std::string& iFile, const std::string& iFunction, int iLine, loggerLevelEnum iLevel)
	{
		std::lock_guard<std::mutex> lock(mMutex);

		std::string wLevel = "";
		std::string wHeader = "";

		switch (iLevel) {
		case eDebug: wLevel = "Debug"; break;
		case eInfo:  wLevel = "Info "; break;
		case eWarn:  wLevel = "Warn "; break;
		case eError: wLevel = "Error"; break;
		}

		mLogCount[iLevel]++;

		wHeader += wLevel + ": " + iFile + "(" + std::to_string(iLine) + ") -> " + iFunction + "() ";

		if (mLogFile.is_open())
		{
			mLogFile << std::left << std::setw(60) << wHeader << " -> " << iMessage << std::endl;
		}

		std::cout << std::left << std::setw(60) << wHeader << " -> " << iMessage << std::endl;
	}

	void LoggerManager::LogCount()
	{
		std::cout << std::endl;
		for (int wLogLevel = eDebug; wLogLevel <= eError; wLogLevel++)
		{
			std::string wLevel;
			switch (wLogLevel) {
			case eDebug: wLevel = "Debug"; break;
			case eInfo:  wLevel = "Info "; break;
			case eWarn:  wLevel = "Warn "; break;
			case eError: wLevel = "Error"; break;
			}
			if (mLogFile.is_open())
			{
				mLogFile << "Number of " << wLevel << " logs: " << mLogCount[wLogLevel] << std::endl;
			}

			std::cout << "Number of " << wLevel << " logs: " << mLogCount[wLogLevel] << std::endl;
		}
	}

	LoggerManager::LoggerManager()
	{
		mLogFile = std::ofstream("QELog.log");
	}

	LoggerManager::~LoggerManager()
	{
		LogCount();
		mLogFile.close();
	}
}