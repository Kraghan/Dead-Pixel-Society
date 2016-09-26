# TMP
add_subdirectory(Memory)
add_subdirectory(GameEngine)
add_subdirectory(GraphicEngine)

# TMP
add_executable(Test Main.cpp)

# TMP
target_link_libraries(Test
        ${SFML_LIB}
        memory
        graphicEngine
        gameEngine)