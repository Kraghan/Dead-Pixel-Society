add_library(memory STATIC
        "${CMAKE_SOURCE_DIR}/src/memory/ResourceManager.cpp"
        "${CMAKE_SOURCE_DIR}/include/memory/Container.hpp"
        "${CMAKE_SOURCE_DIR}/include/memory/Container.inl"
        "${CMAKE_SOURCE_DIR}/include/memory/DefaultAllocator.hpp"
        "${CMAKE_SOURCE_DIR}/include/memory/DefaultAllocator.inl"
        "${CMAKE_SOURCE_DIR}/include/memory/PoolAllocator.hpp"
        "${CMAKE_SOURCE_DIR}/include/memory/PoolAllocator.inl"
        "${CMAKE_SOURCE_DIR}/include/memory/TypeTraits.hpp")