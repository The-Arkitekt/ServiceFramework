set(COMMUNICATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Communication)
set(LOGGER_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/Logger)

####################################
#  Add Service Framework Libraries
####################################

#LOGGER
add_library(Logger ${LOGGER_DIR}/Logger.cpp)
target_include_directories(Logger PUBLIC
  ${LOGGER_DIR}
)

#BUFFER
add_library(Buffer ${COMMUNICATION_DIR}/Buffer.cpp)
target_include_directories(Buffer PUBLIC
  ${LOGGER_DIR}
)
target_link_libraries(Buffer PUBLIC
  Logger
)

#COMMUNICATION BASE
add_library(CommunicationBase ${COMMUNICATION_DIR}/CommunicationBase.cpp)
target_include_directories(CommunicationBase PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(CommunicationBase PUBLIC 
  Logger
  Buffer
)

#SERVER
add_library(Server ${COMMUNICATION_DIR}/Server.cpp)
target_include_directories(Server PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(Server PUBLIC 
  CommunicationBase
  Logger
)

#CLIENT
add_library(Client ${COMMUNICATION_DIR}/Client.cpp)
target_include_directories(Client PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(Client PUBLIC 
  CommunicationBase
  Logger
)