cmake_minimum_required (VERSION 2.8)

project (game)
set(-std=c++11 -Wall)
set(SOURCES_LIST main.cpp Building.h City.cpp City.h House.cpp House.h Park.cpp Park.h Road.cpp Road.h Work.cpp Work.h)
add_executable(game ${SOURCES_LIST})
