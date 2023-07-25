set(COMMUNICATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Communication)
set(UTILITIES_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/Utilities)
set(LOGGER_DIR        ${UTILITIES_DIR}/Logger)
set(XML_DIR           ${UTILITIES_DIR}/Xml)
set(RAPID_XML_DIR     ${XML_DIR}/RapidXml)

####################################
#  Add Service Framework Libraries
####################################

#LOGGER
add_library(Logger ${LOGGER_DIR}/Logger.cpp)
target_include_directories(Logger PUBLIC
  ${LOGGER_DIR}
)

#XML
add_library(Xml ${XML_DIR}/XmlFile.cpp)
target_include_directories(Xml PUBLIC
  ${XML_DR}
  ${RAPID_XML_DIR}
)
target_link_libraries(Xml PUBLIC
  Logger
)

#BUFFER
add_library(Buffer ${COMMUNICATION_DIR}/Buffer.cpp)
target_include_directories(Buffer PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(Buffer PUBLIC
  Logger
)

#SERVER
add_library(Server ${COMMUNICATION_DIR}/Server.cpp)
target_include_directories(Server PUBLIC
  ${COMMUNICATION_DIR}
  ${XML_DIR}
)
target_link_libraries(Server PUBLIC 
  Xml
  Logger
  Buffer
)

#CLIENT
add_library(Client ${COMMUNICATION_DIR}/Client.cpp)
target_include_directories(Client PUBLIC
  ${COMMUNICATION_DIR}
  ${XML_DIR}
)
target_link_libraries(Client PUBLIC 
  Xml  
  Logger
  Buffer
)