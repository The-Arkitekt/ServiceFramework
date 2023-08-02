#include "Client.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{

Client::Client():
  m_connection(),
  m_configured(false)
{
	Utilities::Logger::toStdOutOnly("Client Constructed");
};

}

}
