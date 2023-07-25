#ifndef SERVICE_FRAMEWORK_XML_FILE_H
#define SERVICE_FRAMEWORK_XML_FILE_H

#include "Logger.h"
#include "rapidxml.hpp"
#include <string>

namespace ServiceFramework
{

namespace Utilities
{

class XmlFile
{
public:

	XmlFile(const std::string& filePath);

	const rapidxml::xml_document<char>& getRoot();

private:

	static const unsigned int CONFIG_FILE_MAX_CHARS = 9999U;

	void parseXmlFile(const std::string& filePath);

	rapidxml::xml_document<char> m_root;
};

}

}

#endif //SERVICE_FRAMEWORK_XML_FILE_H
