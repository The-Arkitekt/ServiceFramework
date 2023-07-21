#include "Transmitter.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{


Transmitter::Transmitter():
	CommunicationBase()
{
	Logger::Logger::toStdOutOnly("Transmitter Constructed");
};

}

}
