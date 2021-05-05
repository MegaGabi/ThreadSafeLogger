#pragma once
#include<string>

// There lies Util functions for Logger

enum LogLevel;

std::string getCurrentTimeAsString();
std::string mapLogLevelToString(LogLevel logLevel);
