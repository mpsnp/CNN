project(CNN)

cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

set(CNN_SOURCES 
	Src/CNeuron.cxx
	Src/CPerceptron.cxx
	Src/CTeacher.cxx
	Src/CBackpropagationTeacher.cxx
	Src/CReciever.cxx
)

set(CNN_HEADERS
	Include/CNN.hxx
	Include/CNeuron.hxx
	Include/CGenericNetwork.hxx
	Include/CPerceptron.hxx
	Include/CTeacher.hxx
	Include/CBackpropagationTeacher.hxx
	Include/CReciever.hxx
)

set(CNN_INCLUDE_DIRS Include)

set(CNN_LIBRARIES cnn)

include_directories(${CNN_INCLUDE_DIRS})

add_library(cnn ${CNN_SOURCES} ${CNN_HEADERS})

add_subdirectory(Examples)
