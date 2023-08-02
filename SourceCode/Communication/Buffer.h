#ifndef SERVICE_FRAMEWORK_BUFFER_H
#define SERVICE_FRAMEWORK_BUFFER_H

#include "Message.h"
#include <stdint>
#include <vector>

namespace ServiceFramework
{

namespace Communication
{

class Buffer
{
public:

	Buffer(const uint8_t capacity);

	//Getters
	uint8_t capacity();
	uint8_t size();

	bool push(const Message msg);
	bool pop(Message& msg);
	void clear();

private:

	std::vector<Message> m_bufferContents;

};

}

}



#endif //SERVICE_FRAMEWORK_BUFFER_H
