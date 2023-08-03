#include "TextMessage.h"
#include <iostream>

namespace ServiceFramework
{

namespace Communication
{

TextMessage::TextMessage():
	m_payload(TEXT_MSG_SIZE, TEXT_MSG_ID),
	m_text()
{
}

uint8_t TextMessage::ID()
{
	return TEXT_MSG_ID;
}


bool TextMessage::setText(const std::string& text)
{
	bool success = true;

	if (text.size() > m_payload.size())
	{
		success = false;
	}
	else
	{
		m_text = text;
	}

	return success;
}

std::string TextMessage::getText()
{
	return m_text;
}

uint8_t TextMessage::payloadSize()
{
	return m_payload.size();
}

Payload TextMessage::toPayload()
{
	m_payload.clear();

	for (uint8_t i = 0U; i < m_text.size(); ++i)
	{
		m_payload.setByte(i, static_cast<uint8_t>(m_text[i]));
	}

	return m_payload;
}

bool TextMessage::fromPayload(const Payload& payload)
{
	bool success = false;

	if ((payload.size() == m_payload.size()) &&
		(payload.ID() == TEXT_MSG_ID))
	{
		uint8_t byte = 0U;
		m_text.clear();

		success = true;

		for (uint8_t i = 0U; i < payload.size(); ++i)
		{
			if (!payload.getByte(i, byte))
			{
				success = false;
				break;
			}

			if (byte == 0U)
			{
				break;
			}

			m_text.push_back(static_cast<char>(byte));
		}
	}

	return success;
}

}

}
