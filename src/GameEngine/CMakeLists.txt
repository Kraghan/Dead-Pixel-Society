# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-09-20
cmake_minimum_required(VERSION 3.1)

# Shorcut path
set(SOURCE_PATH "${CMAKE_SOURCE_DIR}/src/GameEngine")
set(HEADER_PATH "${CMAKE_SOURCE_DIR}/include/GameEngine")

# Source files
set(SOURCE_FILE
        "${SOURCE_PATH}/Clock.cpp"
        "${SOURCE_PATH}/GameEngine.cpp")

# Header files
set(HEADER_FILE
        "${HEADER_PATH}/Clock.hpp"
        "${HEADER_PATH}/GameEngine.hpp")

# Creating static library
add_library(engine_game STATIC
        ${SOURCE_FILE}
        ${HEADER_FILE})