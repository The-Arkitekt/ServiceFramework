#ifndef SERVICE_FRAMEWORK_BUFFER_H
#define SERVICE_FRAMEWORK_BUFFER_H

#include "Payload.h"
#include <cstdint>
#include <vector>

namespace ServiceFramework
{

namespace Communication
{

class Buffer
{
public:

	Buffer(const uint8_t capacity, const uint8_t ID);

	//Getters
	uint8_t capacity();
	uint8_t size();

	bool push(const Payload& payload);
	bool pop(Payload& payload);
	void clear();

private:

	uint8_t m_ID;
	uint8_t m_capacity;
	std::vector<Payload> m_data;

};

}

}



#endif //SERVICE_FRAMEWORK_BUFFER_H
