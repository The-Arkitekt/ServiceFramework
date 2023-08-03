#include "Payload.h"

namespace ServiceFramework
{

namespace Communication
{

Payload::Payload(const uint8_t size, const uint8_t ID):
	m_ID(ID),
	m_data(size, 0)
{
}

uint8_t Payload::ID() const
{
	return m_ID;
}

uint8_t Payload::size() const
{
	return m_data.size();
}

void Payload::clear()
{
	for (uint8_t i = 0U; i < m_data.size(); ++i)
	{
		m_data[i] = 0U;
	}
}

bool Payload::setByte(const uint8_t index, const uint8_t data)
{
	bool success = false;
	if (index < m_data.size())
	{
		m_data[index] = data;
		success = true;
	}
	return success;
}

bool Payload::getByte(const uint8_t index, uint8_t& data) const
{
	bool success = false;
	if (index < m_data.size())
	{
		data = m_data[index];
		success = true;
	}
	return success;
}

}

}
