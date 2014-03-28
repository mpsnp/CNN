project(CNN)

cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

set(CNN_SOURCES 
	Src/CNeuron.cxx
)

set(CNN_HEADERS
	Include/CNeuron.hxx
)

set(CNN_INCLUDE_DIRS Include)

set(CNN_LIBRARIES cnn)

include_directories(${CNN_INCLUDE_DIRS})

add_library(cnn ${CNN_SOURCES} ${CNN_HEADERS})