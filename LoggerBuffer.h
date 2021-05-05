#pragma once
#include <sstream>

class Logger;

// This class stores all chained arguments that was passed to operator<<
// After that it sends it's stored values to Logger via destructor

class LoggerBuffer
{
public:
	LoggerBuffer(Logger& logger) :
		_log(logger)
	{}
	LoggerBuffer(LoggerBuffer&& buf) :
		_buffer(std::move(buf._buffer)),
		_log(buf._log)
	{}
	LoggerBuffer(const LoggerBuffer&) = delete;
	LoggerBuffer& operator=(const LoggerBuffer&) = delete;
	LoggerBuffer& operator=(LoggerBuffer&&) = delete;

	template<typename Type>
	LoggerBuffer& operator<<(const Type& toPrint);
	~LoggerBuffer();
private:
	std::stringstream _buffer;
	Logger& _log;
};

template<typename Type>
inline LoggerBuffer& LoggerBuffer::operator<<(const Type& toPrint)
{
	_buffer << toPrint;
	return *this;
}
