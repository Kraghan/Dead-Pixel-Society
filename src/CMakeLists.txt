# TMP
add_subdirectory(memory)

# TMP
add_executable(Test Main.cpp)

# TMP
target_link_libraries(Test
        "${SFML_PATH}/lib/libsfml-graphics-d.a"
        "${SFML_PATH}/lib/libsfml-window-d.a"
        "${SFML_PATH}/lib/libsfml-system-d.a"
        "${SFML_PATH}/lib/libsfml-audio-d.a"
        memory)