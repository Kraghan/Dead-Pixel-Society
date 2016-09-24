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
     * \brief   Allocate a resource of type T and return a const pointer
     * \return  T* A const pointer on T
     */
    static T * const allocateResource();

    /*!
     * \brief   Deallocate a resource of type T
     * \param   resource The resource to deallocate
     */
    static void deallocateResource(T * resource);
};

/*!
 * \see Container.inl for template impl.
 *      Avoid linker template errors
 */
#include "DefaultAllocator.inl"

#endif // __DEFAULT_ALLOCATOR_HPP