cmake_minimum_required (VERSION 2.8)

project (Game)
set(SOURCES_LIST main.cpp Building.h City.cpp City.h House.cpp House.h Park.cpp Park.h Road.cpp Road.h Work.cpp Work.h)

if(DWITH_TEST)
	enable_testing()
	find_package(GTest REQUIRED)
	add_subdirectory(tests)
endif()

add_executable(game ${SOURCES_LIST})
