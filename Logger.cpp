#include "Logger.h"

Logger::Logger(std::ostream& out, const std::string& prefix):
	_out(out),
	_prefix(prefix)
{
}

Logger& Logger::operator()(const LogLevel& logLevel)
{
	this->_logLevel = logLevel;
	return *this;
}

void Logger::log(const std::string& str)
{
	_out << str;
}

Logger::~Logger()
{}
