cmake_minimum_required (VERSION 2.8)
project(TrueConfTestOne)

set(SOURCES
  main.cpp
  ContainersFactory.cpp
)

set(HEADERS
  Constants.h
  Helpers.h
  ContainersFactory.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
