#ifndef SERVICE_FRAMEWORK_CONNECTION_H
#define SERVICE_FRAMEWORK_CONNECTION_H

#include <stdint>

namespace ServiceFramework
{

namespace Communication
{

class Connection
{
public:

	Connection();

	virtual bool connect()          = 0;
	virtual bool disconnect()       = 0;
	virtual bool sendSingleMsg()    = 0;
	virtual bool readSingleMsg()    = 0;

protected:

	Buffer m_transmitBuffer;
	Buffer m_receiveBuffer;
};

}

}

#endif //SERVICE_FRAMEWORK_CONNECTION_H
