# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-09-20
cmake_minimum_required(VERSION 3.1)

# Shorcut path
set(SOURCE_PATH "${CMAKE_SOURCE_DIR}/src/GraphicEngine")
set(HEADER_PATH "${CMAKE_SOURCE_DIR}/include/GraphicEngine")

# Source files
set(SOURCE_FILE
        "${SOURCE_PATH}/Sprite.cpp"
        "${SOURCE_PATH}/GraphicEngine.cpp")

# Header files
set(HEADER_FILE
        "${HEADER_PATH}/Sprite.hpp"
        "${HEADER_PATH}/GraphicEngine.hpp")

# Creating static library
add_library(engine_graphic STATIC
        ${SOURCE_FILE}
        ${HEADER_FILE})