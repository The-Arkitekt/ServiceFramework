#include "Client.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{


Client::Client():
	CommunicationBase()
{
	Logger::Logger::toStdOutOnly("Client Constructed");
};

}

}
