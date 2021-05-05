#include "log.h"

#include <unordered_map> 
#include <iostream>
#include <fstream>
#include <mutex>

namespace 
{
	std::unordered_map<std::string, std::ofstream*> FILE_STREAMS;
}//anonymous namespace

Logger getLogger()
{
	return Logger(std::cout);
}

Logger getLogger(const std::string& fileName, const std::string& prefix)
{
	static std::mutex mutex;
	mutex.lock();
	if (FILE_STREAMS.find(fileName) == FILE_STREAMS.end())
	{
		FILE_STREAMS[fileName] = new std::ofstream(fileName, std::ios::out);
	}
	auto resultLogger = Logger(*(FILE_STREAMS.at(fileName)), prefix);
	mutex.unlock();

	return std::move(resultLogger);
}
