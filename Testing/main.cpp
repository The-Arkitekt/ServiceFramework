#include <iostream>

#include "Logger.h"
#include "XmlFile.h"
#include "TextMessage.h"
#include "Payload.h"
#include "Buffer.h"

int main()
{
	std::cout << "Creating a Client and Server using the ServiceFramework..." << std::endl;

	//ServiceFramework::Communication::Client client;
	//ServiceFramework::Communication::Server server;

	ServiceFramework::Utilities::XmlFile config("../data/ServerConfig.xml");

	std::string outString("First node of config file: ");

	outString += config.getRoot().first_node()->name();
	outString += "\n";
	ServiceFramework::Utilities::Logger::toStdOutOnly(outString);

	ServiceFramework::Communication::TextMessage textMessage;
	textMessage.setText("Hello Matrix");

	outString = "Message Text: ";
	outString += textMessage.getText();
	outString += "\n";

	ServiceFramework::Utilities::Logger::toStdOutOnly(outString);

	ServiceFramework::Utilities::Logger::toStdOutOnly("Encoding Message...\n");

	ServiceFramework::Communication::Payload textMessagePayload = textMessage.toPayload();

	uint8_t byte = 0U;
	for (uint8_t i = 0; i < textMessagePayload.size(); ++i)
	{
		outString = "Encoded message byte: ";

		if (!textMessagePayload.getByte(i, byte))
		{
			outString = "Failed to get encoded byte number: ";
			outString += i;
			outString += "\n";
			ServiceFramework::Utilities::Logger::toStdOutOnly(outString);
			break;
		}

		outString += byte;
		outString += "\n";

		ServiceFramework::Utilities::Logger::toStdOutOnly(outString);
	}

	ServiceFramework::Utilities::Logger::toStdOutOnly("Adding message payload to buffer...\n");

	ServiceFramework::Communication::Buffer buffer(2U, textMessage.ID());
	if (!buffer.push(textMessagePayload))
	{
	    ServiceFramework::Utilities::Logger::toStdOutOnly("Failed to push message to buffer\n");
	}

	ServiceFramework::Utilities::Logger::toStdOutOnly("Getting message from buffer...\n");

	ServiceFramework::Communication::Payload newPayload(textMessage.payloadSize(), textMessage.ID());
	if (!buffer.pop(newPayload))
	{
		ServiceFramework::Utilities::Logger::toStdOutOnly("Failed to get payload from buffer\n");
	}

	ServiceFramework::Utilities::Logger::toStdOutOnly("Decoding received message...\n");

	ServiceFramework::Communication::TextMessage newMessage;

	if (!newMessage.fromPayload(newPayload))
	{
		ServiceFramework::Utilities::Logger::toStdOutOnly("Failed to decode message\n");
	}

	std::cout << "Decoded Message size: " << newMessage.getText().size() << std::endl;


	outString = "Decoded Message: ";
	outString += newMessage.getText();
	ServiceFramework::Utilities::Logger::toStdOutOnly(outString);


	ServiceFramework::Utilities::Logger::toStdOutOnly("Finished Test");

	return 0;
}
