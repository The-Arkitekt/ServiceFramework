#include "Buffer.h"

namespace ServiceFramework
{

namespace Communication
{

Buffer::Buffer(const uint8_t capacity):
	m_bufferContents(std::vector<Message>(capacity))
{
}

uint8_t Buffer::capacity()
{
	return m_bufferContents.capacity();
}

uint8_t Buffer::size()
{
	return m_bufferContents.size();
}

bool Buffer::push(const Message msg)
	bool success = false;

	if (m_bufferContents.size() < m_bufferContents.capacity())
	{
		m_bufferContents.push_back(msg);

		success = true;
	}

	return success;
}

bool buffer::pop(Message& msg)
{
	bool success = false;
	if (m_buferContents.size() > 0U)
	{
		msg = m_bufferContents.back();
		m_bufferContents.pop_back();

		success = true;
	}
}

}

}
