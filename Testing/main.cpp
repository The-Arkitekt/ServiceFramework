#include <iostream>
#include "Logger.h"
#include "XmlFile.h"

int main()
{
	std::cout << "Creating a Client and Server using the ServiceFramework..." << std::endl;

	//ServiceFramework::Communication::Client client;
	//ServiceFramework::Communication::Server server;

	ServiceFramework::Utilities::XmlFile config("../data/ServerConfig.xml");

	std::string testMsg;

	testMsg << "First node of config file: " << config.getRoot().first_node()->name() << std::endl;
	ServiceFramework::Utilities::Logger::toStdOutOnly(testMsg);

	ServiceFramework::Communication::TextMessage textMessage()
	textMessage.setText("Hello Matrix");

	ServiceFramework::Utilities::Logger::toStdOutOnly(textMessage.getText());


	ServiceFramework::Utilities::Logger::toStdOutOnly("Finished Test");

	return 0;
}
