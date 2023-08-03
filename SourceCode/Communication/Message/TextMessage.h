#ifndef SERVICE_FRAMEWORK_TEXT_MESSAGE_H
#define SERVICE_FRAMEWORK_TEXT_MESSAGE_H

#include "Payload.h"
#include <string>

namespace ServiceFramework
{

namespace Communication
{

class TextMessage
{
public:

	TextMessage();

	uint8_t ID();
	bool setText(const std::string& text);
	std::string getText();

	uint8_t payloadSize();
	Payload toPayload();
	bool fromPayload(const Payload& payload);

private:

	static const uint8_t TEXT_MSG_SIZE = 64U;
	static const uint8_t TEXT_MSG_ID   = 1U;


	std::string m_text;
	Payload m_payload;
};

}

}


#endif //SERVICE_FRAMEWORK_TEXT_MESSAGE_H
