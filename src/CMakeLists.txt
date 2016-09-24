# TMP
add_subdirectory(Memory)
add_subdirectory(GameEngine)

# TMP
add_executable(Test Main.cpp)

# TMP
target_link_libraries(Test
        ${SFML_LIB}
        memory
        gameEngine)