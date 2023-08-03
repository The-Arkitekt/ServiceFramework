#ifndef SERVICE_FRAMEWORK_PAYLOAD_H
#define SERVICE_FRAMEWORK_PAYLOAD_H

#include <cstdint>
#include <vector>

namespace ServiceFramework
{

namespace Communication
{

class Payload
{
public:

	Payload(const uint8_t size, const uint8_t ID);

	uint8_t ID() const;
	uint8_t size() const;
	void clear();
	bool setByte(const uint8_t index, const uint8_t data);
	bool getByte(const uint8_t index, uint8_t& data) const;

private:

	uint8_t m_ID;
	std::vector<uint8_t> m_data;
};

}

}

#endif //SERVICE_FRAMEWORK_MESSAGE_H
