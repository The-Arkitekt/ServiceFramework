#include "CommunicationBase.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{

CommunicationBase::CommunicationBase():
	m_buffer()
{
	Logger::Logger::toStdOutOnly("Communication Base Constructed");
}

}

}
