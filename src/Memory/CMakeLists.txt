# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-09-20
cmake_minimum_required(VERSION 3.1)

# Shorcut path
set(SOURCE_PATH "${CMAKE_SOURCE_DIR}/src/Memory")
set(HEADER_PATH "${CMAKE_SOURCE_DIR}/include/Memory")

# Source files
set(SOURCE_FILE
        "${SOURCE_PATH}/ResourceManager.cpp")

# Header files
set(HEADER_FILE
        "${HEADER_PATH}/Container.inl"
        "${HEADER_PATH}/PoolAllocator.inl"
        "${HEADER_PATH}/DefaultAllocator.inl"

        "${HEADER_PATH}/Container.hpp"
        "${HEADER_PATH}/TypeTraits.hpp"
        "${HEADER_PATH}/PoolAllocator.hpp"
        "${HEADER_PATH}/DefaultAllocator.hpp")

# Creating static library
add_library(module_memory STATIC
        ${SOURCE_FILE}
        ${HEADER_FILE})