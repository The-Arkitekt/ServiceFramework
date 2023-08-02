#ifndef SERVICE_FRAMEWORK_TEXT_MESSAGE_H
#define SERVICE_FRAMEWORK_TEXT_MESSAGE_H

#include "Message.h"
#include <string>

namespace ServiceFramework
{

namespace Communication
{

class TextMessage : public Message
{
public:

	TextMessage();
	~TextMessage();
	TextMessage(TextMessage& other);
	TextMessage& operator=(Message const& rhs);

	bool setText(const std::string& text);
	std::string getText();

	bool encode();
	bool decode();

private:

	std::string m_text;
};

}

}


#endif //SERVICE_FRAMEWORK_TEXT_MESSAGE_H
