/*!
 * \brief    Contains the header of the
 *           template class PoolAllocator
 *
 * \file     PoolAllocator.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */

#ifndef __POOL_ALLOCATOR_HPP
#define __POOL_ALLOCATOR_HPP

#define MAX_CAPACITY 100

#include <stdlib.h>

/*!
 * \class   PoolAllocator
 * \brief   Allocates massively memory and provides
 *          a way to get free object in the pool
 *
 */
template <typename T>
class PoolAllocator
{
public:
    /*!
     * \brief   Default constructor
     */
    PoolAllocator();

    /*!
     * \brief   Default destructor, free memory
     */
    ~PoolAllocator();

    /*!
     * \brief   Initializes the pool allocator with capacity Object
     *          of size T
     * \param   capacity The capacity of the pool
     */
    void init(const unsigned int capacity);

    /*!
     * \brief   Allocate an element in the pool
     * \return  The newly allocated element
     */
    T * allocate();

    /*!
     * \brief   Deallocate an element in the pool
     */
    void deallocate(T * object);

    /*!
     * \brief   Construct an object a the adresse of T
     * \param   object The address of the object to construct
     * \return  The pointer on the constructed object
     */
    T * construct(T * object);

    /*!
     * \brief   Call destructor on T
     * \param   object The address of the object to destroy
     */
    void destroy(T * object);

private:

    T * m_head;
    int m_free;
    unsigned int m_capacity;

    /*!
     * \brief   Return the next free index for allocation
     * \return  The index of the next free address
     */
    int getNextIndex(int index);

    /*!
     * \brief   Write nextIndex at the index index
     * \param   index The place to write
     * \param   nextIndex The index to write
     */
    void writeIndex(int index, int nextIndex);

    /*!
     * \brief   Retrieve the index of address from the address
     * \param   address The address of T
     * \return  The index of T in the pool
     */
    int retrieveIndex(T * address);
};

/*!
 * \see PoolAllocator.inl for template impl.
 *      Avoid linker template errors
 */
#include "Memory/PoolAllocator.inl"

#endif // __POOL_ALLOCATOR_HPP