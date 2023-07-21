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

#RECIEVER
add_library(Reciever ${COMMUNICATION_DIR}/Reciever.cpp)
target_include_directories(Reciever PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(Reciever PUBLIC 
  CommunicationBase
  Logger
)

#TRANSMITTER
add_library(Transmitter ${COMMUNICATION_DIR}/Transmitter.cpp)
target_include_directories(Transmitter PUBLIC
  ${COMMUNICATION_DIR}
)
target_link_libraries(Transmitter PUBLIC 
  CommunicationBase
  Logger
)