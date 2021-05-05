#pragma once
#include "Logger.h"

// Gets Logger that prints to console
Logger getLogger();

// Gets Logger that prints to specified file
Logger getLogger(const std::string& fileName, const std::string& prefix = "");