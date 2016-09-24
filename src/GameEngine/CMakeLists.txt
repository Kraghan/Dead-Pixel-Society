add_library(gameEngine STATIC
        GameEngine.cpp
        Clock.cpp
        "${CMAKE_SOURCE_DIR}/include/GameEngine/Clock.hpp"
        "${CMAKE_SOURCE_DIR}/include/GameEngine/GameEngine.hpp")