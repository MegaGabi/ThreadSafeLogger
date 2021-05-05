#include "Logger.h"
#include "Utils.h"

#include <ctime>
#include <unordered_map>

namespace
{
	const std::unordered_map<LogLevel, std::string> LOG_LEVEL_MAP
	{
		{INFO, "INFO"},
		{DEBUG, "DEBUG"},
		{WARNING, "WARNING"},
		{ERROR, "ERROR"}
	};
}// anonymous namespace

std::string getCurrentTimeAsString()
{
	struct tm timeinfo;
	time_t now = time(0);
	char buffer[80];
	localtime_s(&timeinfo, &now);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &timeinfo);
	return buffer;
}

std::string mapLogLevelToString(LogLevel logLevel)
{
	return LOG_LEVEL_MAP.at(logLevel);
}
