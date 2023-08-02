#include "TextMessage.h"

namespace ServiceFramework
{

namespace Communication
{

TextMessage::TextMessage():
	Message(),
	m_text()
{
}

TextMessage::~TextMessage()
{
}

TextMessage::TextMessage(const TextMessage& other)
	m_text(other.m_text)
{
}

TextMessage& TextMessage::operator=(const TextMessage& rhs)
{
	m_text = rhs.m_text;
}

bool TextMessage::setText(const std::string& text)
{
	bool success = false;

	if (text.size() < MAX_MSG_SIZE)
	{
		m_text = text;
		success = true;
	}
	return success;
}

std::string TextMessage::getText()
{
	return m_text;
}

bool TextMessage::encode()
{
	bool success = true;

	clear();

	for (uint8_t i = 0U; i < m_text.size(); ++i)
	{
		if (i > MAX_MSG_SIZE)
		{
			success = false;
			break;
		}

		pushByte(static_cast<uint8_t>(m_text[i]));
	}
	return success;
}

bool TextMessage::decode()
{
	bool success = true;
	uint8_t byte;

	m_text.clear();

	for (uint8_t i = 0U; i < size(); ++i)
	{
		if (i > MAX_MSG_SIZE)
		{
			success = false;
			break;
		}

		if (!getByte(i, byte))
		{
			success = false;
			break;
		}
		m_text.push_back(static_cast<char>(byte));
	}
	return success;
}

}
