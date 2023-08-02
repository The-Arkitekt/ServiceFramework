#ifndef SERVICE_FRAMEWORK_SERVER_H
#define SERVICE_FRAMEWORK_SERVER_H

#include "Connection.h"
#include "Buffer.h"
#include "XmlFile.h"
#include <vector>

namespace ServiceFramework
{

namespace Communication
{

class Server
{
public:
	Server();

	bool configure(const Utilities::XmlFile& configFile);

private:
	std::vector<Connection> m_connections;
	bool m_configured;
};

}

}

#endif //SERVICE_FRAMEWORK_SERVER_H
