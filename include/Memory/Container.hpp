/*!
 * \brief    Contains the header of the
 *           template class Container
 *
 * \file     Container.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */

#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <chrono>
#include <algorithm>
#include <unordered_map>
#include "TypeTraits.hpp"
#include "DefaultAllocator.hpp"

/*!
 * \class Container
 * \brief Stores U and provides basic accessors on it
 *
 */
template <typename T, typename U,
    class Allocator = DefaultAllocator<U>,
    class Hash = std::hash<T> >
class Container
{
public :
    /*!
     * \brief   Intialize the iterator with begin
     */
    explicit Container();

    /*!
     * \brief   Free all allocated memory and clear the map
     */
    virtual ~Container();

    /*!
     * \brief   Return the resource referenced by the given key
     * \param   key A const reference or value on/of the key
     * \see     TypeTraits.hpp
     * \return  U* a pointer on the resource if it exists
     * \return  nullptr if the key doesn't exist
     */
    U * const getResource(typename TypeTraits<T>::TypeSize key);

    /*!
     * \brief   Deallocate the memory of the objet referenced by the key
     * \param   key A const reference or value on/of the key to find
     *          the object to delete
     * \see     TypeTraits.hpp
     */
    void freeResource(typename TypeTraits<T>::TypeSize key);

    /*!
     * \brief   Allocate a resource and return a pointer on the new resource
     * \param   key A const reference or value on/of the key
     * \see     TypeTraits.hpp
     * \return  U* A pointer on the recently created resource
     * \return  nullptr Return a null pointer if the key already exists
     */
    U * const loadResource(typename TypeTraits<T>::TypeSize key);

    /*!
     * \brief   Return the current allocator to provide access
     *          to some methods
     * \return  A pointer on the current allocator
     */
    Allocator * getAllocator();

    /*!
     * \brief   Return a random value in the map
     * \return  A random value
     */
    U * const getRandom();

private :

    Allocator m_allocator;
    std::unordered_map < T, U*, Hash> m_resources;
    typename std::unordered_map < T, U*, Hash> ::iterator m_iterator;

    /*!
     * \brief   Check if the key exists in the resource map
     * \param   key A const reference on the key to check
     * \return  true if the key exists
     * \return  false if the key doesn't exist
     */
    const bool checkKey(typename TypeTraits<T>::TypeSize key);
};

/*!
 * \see Container.inl for template impl.
 *      Avoid linker template errors
 */
#include "Memory/Container.inl"

#endif // __CONTAINER_HPP