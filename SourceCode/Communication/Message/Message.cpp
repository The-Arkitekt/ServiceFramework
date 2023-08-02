#include "Message.h"

namespace ServiceFramework
{

namespace Communication
{

Message::Message():
	m_data()
{
}

Message::~Message()
{
}

Message::Message(Message const& other):
	m_data(other.m_data)
{
}

Message& Message::operator=(Message const& rhs)
{
	m_data = rhs.m_data;
	return *this;
}

uint8_t Message::size()
{
	return m_data.size();
}

void Message::clear()
{
	m_data.clear();
}

bool Message::pushByte(const uint8_t data)
{
	bool success = false;
	if (m_data.size() < MAX_MSG_SIZE)
	{
		m_data.push_back(data);
		success = true;
	}
	return success;
}

bool Message::getByte(const uint8_t index, uint8_t& data)
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
