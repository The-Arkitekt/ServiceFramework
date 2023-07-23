//	std::ifstream configFile(configFilePath.c_str());
//	std::ostringstream configFileString;
//	configFileString << configFile.rdbuf();
//
//	Logger::Logger::toStdOutOnly(configFileString.str().c_str());
//
//
//	rapidxml::xml_document<char> config;
//	config.parse<0>(static_cast<char*>(configFileString.str().c_str()));
//
//	//rapidxml::xml_document<> doc;
//	//doc.parse<0>(configFileString.get());
