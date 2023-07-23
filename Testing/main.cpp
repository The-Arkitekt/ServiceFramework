#include <iostream>
#include "Logger.h"
#include "Server.h"
#include "Client.h"

int main()
{
	std::cout << "Creating a Client and Server using the ServiceFramework..." << std::endl;

	ServiceFramework::Communication::Client client;
	ServiceFramework::Communication::Server server;

	//server.configure("../data/ServerConfig.xml");

	ServiceFramework::Utilites::Logger::toStdOutOnly("Finished Test");

	return 0;
}
