/*!
 * \brief    Contains the header of the
 *           template class DrawableManager
 *
 * \file     DrawableManager.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     29/09/2016
 */

#ifndef __DRAWABLE_MANAGER_HPP
#define __DRAWABLE_MANAGER_HPP

#include <vector>

template <typename T>
class DrawableManager
{
public:

    /*!
     * \brief   Constructor
     */
    DrawableManager();

    /*!
     * \brief   Destructor
     */
    ~DrawableManager();

    /*!
     * \brief   Initialize the manager with size element
     */
    void init(unsigned int size);

    /*!
     * \brief   Return an available drawable in the list
     * \return  If none, nullptr
     */
    T const * getFreeDrawable();

    /*!
     * \brief   Return the list of drawables
     * \return  The list of drawables
     */
    T const * getDrawableList() const;

    /*!
     * \brief   Return the count of drawables in the list
     * @return  The number of drawables
     */
    unsigned int getDrawableCount() const;

private:

    unsigned int m_size;
    T * m_drawableList;
};

#include "GraphicEngine/DrawableManager.inl"

#endif // __DRAWABLE_MANAGER_HPP