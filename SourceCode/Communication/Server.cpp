#include "Server.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{

Server::Server():
	CommunicationBase()
{
	Logger::Logger::toStdOutOnly("Server Constructed");
}


}

}
