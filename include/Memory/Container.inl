#include "Memory/Container.hpp"

template <typename T, typename U, class Allocator, class Hash>
Container<T, U, Allocator, Hash>::Container()
{
    m_iterator = m_resources.begin();
}

template <typename T, typename U, class Allocator, class Hash>
Container<T, U, Allocator, Hash>::~Container()
{
    m_iterator = m_resources.begin();
    for(; m_iterator != m_resources.end(); ++m_iterator) {
        m_allocator.deallocate(m_iterator->second);
    }

    m_resources.clear();
}

template <typename T, typename U, class Allocator, class Hash>
const bool Container<T, U, Allocator, Hash>
::checkKey(typename TypeTraits<T>::TypeSize key)
{
    m_iterator = m_resources.find(key);
    return m_iterator != m_resources.end();
}

template <typename T, typename U, class Allocator, class Hash>
U * const Container<T, U, Allocator, Hash>
::getResource(typename TypeTraits<T>::TypeSize key)
{
    if(!checkKey(key)) return nullptr;
    return m_iterator->second;
}

template <typename T, typename U, class Allocator, class Hash>
void Container<T, U, Allocator, Hash>
::freeResource(typename TypeTraits<T>::TypeSize key)
{
    if(!checkKey(key)) return;

    m_allocator.deallocate(m_iterator->second);
    m_resources.erase(m_iterator);
}

template <typename T, typename U, class Allocator, class Hash>
U * const Container<T, U, Allocator, Hash>
::loadResource(typename TypeTraits<T>::TypeSize key)
{
    if(checkKey(key)) return nullptr;

    U * resource = m_allocator.allocate();
    m_allocator.construct(resource);

    m_resources.emplace(key, resource);

    return resource;
}

template <typename T, typename U, class Allocator, class Hash>
Allocator * Container<T, U, Allocator, Hash>
::getAllocator()
{
    return &m_allocator;
}

template <typename T, typename U, class Allocator, class Hash>
U * const Container<T, U, Allocator, Hash>
::getRandom()
{
    // Checking size
    if(m_resources.size() == 0) return nullptr;

    // Generation seed
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Creating buffer to shuffle value
    std::vector < U * > _buffer;

    // Filling the vector
    for(auto it = m_resources.begin(); it != m_resources.end(); ++it)
    {
        _buffer.push_back(it->second);
    }

    // Shuffle the vector
    std::shuffle(_buffer.begin(), _buffer.end(), std::default_random_engine(seed));

    // Returning the first iterator value
    return *_buffer.begin();
}
