#include "Server.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{

Server::Server():
  m_connections(),
  m_buffers    (),
  m_configured (false)
{
	Utilities::Logger::toStdOutOnly("Server Constructed");
}


}

}
