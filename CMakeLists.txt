cmake_minimum_required (VERSION 2.8)

project (game)
set(CMAKE_CXX_FLAGS -std=c++11) 
set(SOURCES_LIST 
	Building.h 
	City.cpp 
	City.h 
	CityState.cpp
	CityState.h
	Graphics.cpp 
	Graphics.h 
	House.cpp 
	House.h 
	Memento.cpp
	Memento.h
	Park.cpp 
	Park.h 
	Parser.cpp 
	Parser.h 
	ParserAdapter.cpp 
	ParserAdapter.h 
	Road.cpp 
	Road.h 
	State.cpp
	State.h
	Strategy.cpp
	Strategy.h
	Work.cpp 
	Work.h)

if(DEBUG) 
	set(CMAKE_BUILD_TYPE Debug) 
else()
	set(CMAKE_BUILD_TYPE Release) 
endif() 

if(WITH_TEST)	
	enable_testing()
	find_package(GTest REQUIRED) 
	include_directories(${GTEST_INCLUDE_DIRS}) 
	add_executable(game ${SOURCES_LIST} test.cpp)
	target_link_libraries(game ${GTEST_LIBRARIES} pthread) 
else()
	add_executable(game ${SOURCES_LIST} main.cpp)
endif()
