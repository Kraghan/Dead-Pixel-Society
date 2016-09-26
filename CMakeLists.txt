# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-09-20
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
    message(FATAL_ERROR "This plateforme is currently not supported")
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
    file(WRITE ${CMAKE_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG} "C:/../SFML | /home/../SFML")
    message(WARNING "CMakeConfig.txt file created")
endif()

# Writing default messages
message(STATUS "Detected Plateforme : ${PLATEFORME}")
message(STATUS "Game version ${GAME_VERSION_MAJOR}.${GAME_VERSION_MINOR}.${GAME_VERSION_PATCH}")

# Project settings
set(CMAKE_CXX_FLAGS_DEBUG "${COMPILER_FLAGS} ${DEBUG_FLAGS}" CACHE STRING "release flags" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "${COMPILER_FLAGS} ${RELEASE_FLAGS}" CACHE STRING "debug flags" FORCE)

# Getting properties
# -> SFML_PATH
file(STRINGS "CMakeConfig.txt" SFML_PATH)
message(STATUS "SFML PATH : ${SFML_PATH}")

# Global usefull variables
set(EXENAME_RELEASE DeadPixelSociety_REL)
set(EXENAME_DEBUG   DeadPixelSociety_DBG)

if(NOT COMPILATION_MODE)
    message(STATUS "(Warning) : No argument is specified, debug by default")
    set(COMPILATION_MODE "DEBUG")
endif()

if(${COMPILATION_MODE} STREQUAL "RELEASE")
    message(STATUS "Compilation mode : RELEASE MODE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "compile flags" FORCE)

    if(PLATEFORME STREQUAL "WINDOWS")
        set(EXENAME ${EXENAME_RELEASE})
        list(APPEND SFML_RELEASE_LIB
                "${SFML_PATH}/lib/libsfml-graphics.a"
                "${SFML_PATH}/lib/libsfml-window.a"
                "${SFML_PATH}/lib/libsfml-system.a"
                "${SFML_PATH}/lib/libsfml-audio.a")

    elseif(PLATEFORME STREQUAL "LINUX")
        set(EXENAME ${EXENAME_RELEASE})
        list(APPEND SFML_RELEASE_LIB
                "${SFML_PATH}/lib/libsfml-graphics.so"
                "${SFML_PATH}/lib/libsfml-window.so"
                "${SFML_PATH}/lib/libsfml-system.so"
                "${SFML_PATH}/lib/libsfml-audio.so")

    endif()

    set(SFML_LIB ${SFML_RELEASE_LIB})
    message(STATUS "Executable name : ${EXENAME}")

else()
    message(STATUS "Compilation mode : DEBUG MODE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "compile flags" FORCE)
    set(SFML_LIB ${SFML_DEBUG_LIB})

    if(PLATEFORME STREQUAL "WINDOWS")
        set(EXENAME ${EXENAME_DEBUG})
        list(APPEND SFML_DEBUG_LIB
                "${SFML_PATH}/lib/libsfml-graphics-d.a"
                "${SFML_PATH}/lib/libsfml-window-d.a"
                "${SFML_PATH}/lib/libsfml-system-d.a"
                "${SFML_PATH}/lib/libsfml-audio-d.a")

    elseif(PLATEFORME STREQUAL "UNIX")
        set(EXENAME ${EXENAME_DEBUG})
        list(APPEND SFML_DEBUG_LIB
                "${SFML_PATH}/lib/libsfml-graphics.so"
                "${SFML_PATH}/lib/libsfml-window.so"
                "${SFML_PATH}/lib/libsfml-system.so"
                "${SFML_PATH}/lib/libsfml-audio.so")
    endif()

    set(SFML_LIB "${SFML_DEBUG_LIB}")
    message(STATUS "Executable name : ${EXENAME}")
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
message(STATUS "Output  path : ${CMAKE_SOURCE_DIR}/bin")

# include search path
include_directories(
        include
        ${SFML_PATH}/include)

# Adding sub directories
# Sources directories
add_subdirectory(src)
