# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Variables
# The version number.
set(GAME_VERSION_MAJOR 0)
set(GAME_VERSION_MINOR 1)
set(GAME_VERSION_PATCH 0)

# File and directories
set(PROJECT_BIN bin)
set(PROJECT_RES res)
set(PROJECT_CMAKE_CONFIG CMakeConfig.txt)

set(DEBUG_FLAGS "-Wall -g")
set(RELEASE_FLAGS "-O2")
set(COMPILER_FLAGS "-std=c++11")

# CMake build script
# Checking the plateforme
if(WIN32)
    set(PLATEFORME WINDOWS)
elseif(UNIX)
    set(PLATEFORME UNIX)
else()
    set(PLATEFORME NOT_SUPPORTED)
    message(FATAL_ERROR "This plateform is currently not supported")
endif()

# Checking project structure
if(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${PROJECT_BIN}/)
    file(MAKE_DIRECTORY ${PROJECT_BIN})
    message(WARNING "Bin directory created")

elseif(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${PROJECT_RES}/)
    file(MAKE_DIRECTORY ${PROJECT_RES})
    message(WARNING "Res directory created")
endif()

# Checking CMakeConfig file
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG})
    file(WRITE ${CMAKE_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG} "<PATH TO SFML>")
    message(WARNING "CMakeConfig.txt file created")
endif()

# Writing default messages
message(STATUS "Detected Plateforme : ${PLATEFORME}")
message(STATUS "Game version ${GAME_VERSION_MAJOR}.${GAME_VERSION_MINOR}.${GAME_VERSION_PATCH}")

# Project settings
set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${DEBUG_FLAGS}" CACHE STRING "compile flags" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "${COMPILER_FLAGS} ${DEBUG_FLAGS}" CACHE STRING "release flags" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "${COMPILER_FLAGS} ${RELEASE_FLAGS}" CACHE STRING "debug flags" FORCE)

# Getting properties
# -> SFML_PATH
file(STRINGS "CMakeConfig.txt" SFML_PATH)
message(STATUS "SFML PATH : ${SFML_PATH}")

# include search path
include_directories(include)

# Adding sub directories
# Sources directories
add_subdirectory(src)


