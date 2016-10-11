#include "Memory/DefaultAllocator.hpp"

template <typename T>
inline T * DefaultAllocator<T>::allocate() const
{
    return (T *) ::operator new (sizeof(T));
}

template <typename T>
inline T * DefaultAllocator<T>::construct(T * object) const
{
    return new(object) T();
}

template <typename T>
inline void DefaultAllocator<T>::destroy(T * object) const
{
    object->~T();
}

template <typename T>
inline void DefaultAllocator<T>::deallocate(T * object) const
{
    delete object;
}