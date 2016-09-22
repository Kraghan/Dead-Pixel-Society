# TMP
add_subdirectory(memory)

# TMP
add_executable(Test Main.cpp)

# TMP
target_link_libraries(Test memory)