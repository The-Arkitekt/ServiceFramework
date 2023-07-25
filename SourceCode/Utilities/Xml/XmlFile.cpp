#include "XmlFile.h"
#include <fstream>
#include <iostream>

namespace ServiceFramework
{

namespace Utilities
{

XmlFile::XmlFile(const std::string& filePath):
	m_root()
{
	parseXmlFile(filePath);
}

const rapidxml::xml_document<char>& XmlFile::getRoot()
{
	return m_root;
}

void XmlFile::parseXmlFile(const std::string& filePath)
{
	bool success = true;

	std::ifstream fileStream(filePath);
	std::string fileString;

	char token = 0U;
	for (unsigned int i = 0U; i < CONFIG_FILE_MAX_CHARS; ++i)
	{
		if (fileStream.get(token))
		{
			fileString.push_back(token);
		}
		else
		{
			break;
		}
	}

	fileString.push_back('\0');

	m_root.parse<0>(const_cast<char*>(fileString.c_str()));
}


}

}
