#ifndef SERVICE_FRAMEWORK_CONNECTION_H
#define SERVICE_FRAMEWORK_CONNECTION_H

#include <string>
#include <stdint>

namespace ServiceFramework
{

namespace Communication
{

class Connection
{
public:

	virtual bool configure(const uint8_t connectionId, const std::string& configFilePath);

	virtual bool connect()
};

}

}

#endif //SERVICE_FRAMEWORK_CONNECTION_H
