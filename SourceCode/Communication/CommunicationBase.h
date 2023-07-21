#ifndef SERVICE_FRAMEWORK_COMMUNICATION_BASE
#define SERVICE_FRAMEWORK_COMMUNICATION_BASE

#include "Buffer.h"

namespace ServiceFramework
{

namespace Communication
{

class CommunicationBase
{
protected:

	CommunicationBase();

	Buffer m_buffer;

};

}

}


#endif //SERVICE_FRAMEWORK_COMMUNICATION_BASE
