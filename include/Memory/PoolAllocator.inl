#include "Memory/PoolAllocator.hpp"

template <typename T>
PoolAllocator<T>::PoolAllocator() :
m_head(nullptr),
m_free(0),
m_capacity(0)
{
    // TODO
}

template <typename T>
PoolAllocator<T>::~PoolAllocator()
{
    if(m_head != nullptr) free(m_head);
}

template <typename T>
void PoolAllocator<T>::init(const unsigned int capacity)
{
    if(MAX_CAPACITY < capacity) return;

    m_head = (T *)malloc(capacity * sizeof(T));

    m_free = 0;
    m_capacity = capacity;

    // Initialize pool indexes
    for (unsigned int i = 0; i < m_capacity - 1; ++i)
    {
        writeIndex(i, i + 1);
    }

    // The last points on nullptr
    writeIndex(m_capacity - 1, -1);
}

template <typename T>
T * PoolAllocator<T>::allocate()
{
    if(m_free == -1) return nullptr;

    T * free = &m_head[m_free];
    m_free = getNextIndex(m_free);

    return free;
}

template <typename T>
void PoolAllocator<T>::deallocate(T * object)
{
    // Calling destructor
    destroy(object);

    // Retrieving index
    int index = retrieveIndex(object);

    // Managing pool indexes
    if (m_free > index || m_free == -1)
    {
        writeIndex(index, m_free);
        m_free = index;
    }
    else
    {
        int nextIndex = getNextIndex(m_free);
        int lastIndex = m_free;

        while (index > nextIndex)
        {
            lastIndex = nextIndex;
            nextIndex = getNextIndex(nextIndex);
        }

        writeIndex(lastIndex, index);
        writeIndex(index, nextIndex);
    }
}

template <typename T>
T * PoolAllocator<T>::construct(T * object)
{
    // Using placement new
    T * constructed = new (object) T();
    return constructed;
}

template <typename T>
void PoolAllocator<T>::destroy(T * object)
{
    // Explicit destructor call
    object->~T();
}

template <typename T>
int PoolAllocator<T>::getNextIndex(int index)
{
    // Getting the next free index
    // at the address of m_head[index]
    return *((int *)((void *)(&m_head[index])));
}

template <typename T>
void PoolAllocator<T>::writeIndex(int index, int nextIndex)
{
    // Writing at the address of m_head[index]
    // the next free index (address by extension)
    *((int *)((void *)(&m_head[index]))) = nextIndex;
}

template <typename T>
int PoolAllocator<T>::retrieveIndex(T * address)
{
    // Retrieve index by subtracting head and object address
    // and dividing by sizeof T
    return (((int)address - (int)m_head) / sizeof(T));
}
