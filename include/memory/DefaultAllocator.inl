#include "DefaultAllocator.hpp"

template <typename T>
inline T * const DefaultAllocator<T>::allocateResource()
{
    return new T();
}

template <typename T>
inline void DefaultAllocator<T>::deallocateResource(T * resource)
{
    delete resource;
}