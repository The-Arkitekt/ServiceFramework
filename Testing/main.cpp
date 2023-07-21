#include <iostream>
#include "Logger.h"
#include "Server.h"
#include "Client.h"

int main()
{
	std::cout << "Creating a Client and Server using the ServiceFramework..." << std::endl;

	ServiceFramework::Communication::Client client;
	ServiceFramework::Communication::Server server;

	ServiceFramework::Logger::Logger::toStdOutOnly("Finished Test");

	return 0;
}
