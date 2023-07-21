#include <iostream>
#include "Logger.h"

namespace ServiceFramework
{

namespace Logger
{

Logger::Logger()
{
}

void Logger::toStdOutOnly(const std::string& msg)
{
	std::cout << msg << std::endl;
}

}

}
