#include "Container.hpp"

template <typename T, typename U, class Allocator, class Hash>
Container<T, U, Allocator, Hash>::Container()
{
    m_iterator = m_resources.begin();
}

template <typename T, typename U, class Allocator, class Hash>
Container<T, U, Allocator, Hash>::~Container()
{
    m_iterator = m_resources.begin();
    for(; m_iterator != m_resources.end(); ++m_iterator)
        m_allocator.deallocateResource(m_iterator->second);

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

    m_allocator.deallocateResource(m_iterator->second);
    m_resources.erase(m_iterator);
}

template <typename T, typename U, class Allocator, class Hash>
U * const Container<T, U, Allocator, Hash>
::loadResource(typename TypeTraits<T>::TypeSize key)
{
    if(checkKey(key)) return nullptr;

    U * resource = m_allocator.allocateResource();
    m_resources.emplace(key, resource);

    return resource;
}