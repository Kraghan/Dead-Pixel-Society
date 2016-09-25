/*!
 * \brief    Default Policy of allocation
 * \file     DefaultAllocator.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */

#ifndef __DEFAULT_ALLOCATOR_HPP
#define __DEFAULT_ALLOCATOR_HPP

/*!
 * \class   DefaultAllocator
 * \brief   Contains default policy header for allocation
 *
 */
template <typename T>
class DefaultAllocator
{
public:

    /*!
     * \brief   Allocate a storage space of size T and return a pointer on it
     * \return  T* A pointer on allocated space
     */
    T * allocate() const;

    /*!
     * \brief   Construct an object from T *
     * \return  T* A pointer on the constructed object
     */
    T * construct(T * object) const;

    /*!
     * \brief   Call the destructor of the object
     * \param   object A pointer on the object to destroy
     */
    void destroy(T * object) const;

    /*!
     * \brief   Deallocate a resource of type T
     * \param   resource The resource to deallocate
     */
    void deallocate(T * resource) const;
};

/*!
 * \see Container.inl for template impl.
 *      Avoid linker template errors
 */
#include "Memory/DefaultAllocator.inl"

#endif // __DEFAULT_ALLOCATOR_HPP