# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-09-20
cmake_minimum_required(VERSION 3.1)

# Getting sources
file(GLOB_RECURSE SOURCE_FILE *)

# Creating main executable
# Should be only the main file
add_executable(${EXENAME} ${SOURCE_FILE} ../include/WorldMap/WorldMap.hpp.h ../include/WorldMap/WorldMap.hpp WorldMap/WorldMap.cpp)

# Linking all static libraries
target_link_libraries(${EXENAME} ${SFML_LIB})