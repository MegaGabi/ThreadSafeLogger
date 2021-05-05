#pragma once
#include "Utils.h"
#include "LoggerBuffer.h"

#include <ostream>
#include <string>

enum LogLevel
{
	INFO,
	DEBUG,
	WARNING,
	ERROR
};

class Logger
{
public:
	Logger(std::ostream& out, const std::string& prefix = "");
	Logger& operator()(const LogLevel& logLevel);
	void log(const std::string& str);
	virtual ~Logger();

	template<typename Type>
	LoggerBuffer operator<<(const Type& toPrint);
protected:
	std::ostream& _out;
	LogLevel _logLevel = INFO;
	std::string _prefix = "";
};

template<typename Type>
inline LoggerBuffer Logger::operator<<(const Type& toPrint)
{
	LoggerBuffer buffer(*this);

	buffer << getCurrentTimeAsString() << "; "
				<< mapLogLevelToString(_logLevel) << "; "
				<< _prefix << "(" << std::this_thread::get_id() << "): " 
				<< toPrint;

	return std::move(buffer);
}
