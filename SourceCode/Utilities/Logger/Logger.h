#ifndef SERVICE_FRAMEWORK_LOGGER_H
#define SERVICE_FRAMEWORK_LOGGER_H

#include <string>

namespace ServiceFramework
{

namespace Utilities
{

class Logger
{
public:
	static void toStdOutOnly(const std::string& msg);

private:
	Logger();

};

}

}

#endif //SERVICE_FRAMEWORK_LOGGER_H
