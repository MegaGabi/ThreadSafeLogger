#include "LoggerBuffer.h"
#include "Logger.h"

// Send stored chain as a string to Logger
LoggerBuffer::~LoggerBuffer()
{
	_log.log(_buffer.str());
}
