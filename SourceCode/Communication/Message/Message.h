#ifndef SERVICE_FRAMEWORK_MESSAGE_H
#define SERVICE_FRAMEWORK_MESSAGE_H

#include <cstdint>
#include <vector>

namespace ServiceFramework
{

namespace Communication
{

class Message
{
public:

	virtual bool encode() = 0;
	virtual bool decode() = 0;

protected:

	static const uint8_t MAX_MSG_SIZE = 32;

	Message();
	~Message();
	Message(const Message& other);
	Message& operator=(Message const& rhs);

	uint8_t size();
	void clear();
	bool pushByte(const uint8_t data);
	bool getByte(const uint8_t index, uint8_t& data);

private:

	std::vector<uint8_t> m_data;


};

}

}

#endif //SERVICE_FRAMEWORK_MESSAGE_H
