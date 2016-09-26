add_library(memory STATIC
        "${CMAKE_SOURCE_DIR}/src/Memory/ResourceManager.cpp"
        "${CMAKE_SOURCE_DIR}/include/Memory/Container.hpp"
        "${CMAKE_SOURCE_DIR}/include/Memory/Container.inl"
        "${CMAKE_SOURCE_DIR}/include/Memory/DefaultAllocator.hpp"
        "${CMAKE_SOURCE_DIR}/include/Memory/DefaultAllocator.inl"
        "${CMAKE_SOURCE_DIR}/include/Memory/PoolAllocator.hpp"
        "${CMAKE_SOURCE_DIR}/include/Memory/PoolAllocator.inl"
        "${CMAKE_SOURCE_DIR}/include/Memory/TypeTraits.hpp")