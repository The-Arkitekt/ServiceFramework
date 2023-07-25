cmake_minimum_required(VERSION 3.16)

set (SERVICE_FRAMEWORK_SOURCE_DIR ${CMAKE_SOURCE_DIR}/../SourceCode)
set (SERVICE_FRAMEWORK_BINARY_DIR ${SERVICE_FRAMEWORK_SOURCE_DIR}/bld)
set (EXECUTABLE_NAME              ServiceFramework)

project(ServiceFrameworkTest C CXX ASM)
set(SOURCES
  main.cpp
)

add_executable(${EXECUTABLE_NAME}
  ${SOURCES}
)

add_subdirectory(${SERVICE_FRAMEWORK_SOURCE_DIR} ${SERVICE_FRAMEWORK_BINARY_DIR})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC 
  Logger
  Xml
  Server
  Client
)

target_include_directories(${EXECUTABLE_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
)