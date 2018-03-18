cmake_minimum_required (VERSION 2.8)

project (game)
set(CMAKE_CXX_FLAGS -std=c++11) 
set(SOURCES_LIST Building.h City.cpp City.h House.cpp House.h Park.cpp Park.h Road.cpp Road.h Work.cpp Work.h main.cpp)

#if(DEBUG) 
#	set(CMAKE_BUILD_TYPE Debug) 
#endif() 
#
#if(WITH_TEST)
#	enable_testing()
#	find_package(GTest REQUIRED)
#	include_directories(${GTEST_INCLUDE_DIRS})
#	set(SOURCES_LIST ${SOURCES_LIST} test.cpp)
#else()
#	set(SOURCES_LIST ${SOURCES_LIST} main.cpp)
#endif()
#
add_executable(game ${SOURCES_LIST})
