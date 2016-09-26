# Dead Pixel Society project
# Author : Aredhele
# Date   : 2016-09-20
cmake_minimum_required(VERSION 3.1)

# Adding target libraries
add_subdirectory(Memory)
add_subdirectory(GameEngine)
add_subdirectory(GraphicEngine)

# Creating main executable
# Should be only the main file
add_executable(${EXENAME} Main.cpp)

# Linking all static libraries
target_link_libraries(${EXENAME}
        ${SFML_LIB}
        module_memory
        engine_graphic
        engine_game)