#ifndef SERVICE_FRAMEWORK_CLIENT_H
#define SERVICE_FRAMEWORK_CLIENT_H

#include "Connection.h"
#include "Buffer.h"
#include "XmlFile.h"

namespace ServiceFramework
{

namespace Communication
{

class Client
{
public:
	Client();

	bool configure(const Utilities::XmlFile& configFile);

private:
	Connection m_connection;
	Buffer m_buffer;
	bool m_configured;
};

}

}


#endif //SERVICE_FRAMEWORK_TRANSMITTER_H
