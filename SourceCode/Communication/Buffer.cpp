#include "Buffer.h"

namespace ServiceFramework
{

namespace Communication
{

Buffer::Buffer(const uint8_t capacity, const uint8_t ID):
	m_ID(ID),
    m_capacity(capacity),
	m_data()
{
}

uint8_t Buffer::capacity()
{
	return m_capacity;
}

uint8_t Buffer::size()
{
	return m_data.size();
}

bool Buffer::push(const Payload& payload)
{
	bool success = false;

	if ((m_data.size() < m_capacity) &&
		(payload.ID() == m_ID))
	{
		m_data.push_back(payload);

		success = true;
	}

	return success;
}

bool Buffer::pop(Payload& payload)
{
	bool success = false;

	if (m_data.size() > 0)
	{
		payload = m_data.back();
		m_data.pop_back();

		success = true;
	}

	return success;
}

}

}
