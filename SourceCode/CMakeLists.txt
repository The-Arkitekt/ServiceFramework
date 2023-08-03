set(COMMUNICATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Communication)
set(MESSAGE_DIR       ${COMMUNICATION_DIR}/Message)
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
  ${XML_DIR}
  ${RAPID_XML_DIR}
)
target_link_libraries(Xml PUBLIC
  Logger
)

#MESSAGING
add_library(Payload ${MESSAGE_DIR}/Payload.cpp)
target_include_directories(Payload PUBLIC
  ${MESSAGE_DIR}
)

add_library(TextMessage ${MESSAGE_DIR}/TextMessage.cpp)
target_include_directories(TextMessage PUBLIC
  ${MESSAGE_DIR}
)
target_link_libraries(TextMessage PUBLIC
  Payload
)

#BUFFER
add_library(Buffer ${COMMUNICATION_DIR}/Buffer.cpp)
target_include_directories(Buffer PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(Buffer PUBLIC
  Payload
)

