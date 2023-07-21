#include "Reciever.h"
#include "Logger.h"

namespace ServiceFramework
{

namespace Communication
{

Reciever::Reciever():
	CommunicationBase()
{
	Logger::Logger::toStdOutOnly("Receiver Constructed");
}


}

}
