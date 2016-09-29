/*!
 * \brief    Contains the header of the
 *           class ResourceManager
 *
 * \file     ResourceManager.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     28/09/2016
 */

#ifndef __RESOURCE_MANAGER_HPP
#define __RESOURCE_MANAGER_HPP

#include "GraphicEngine/Sprite.hpp"
#include "GraphicEngine/GraphicEngine.hpp"

class ResourceManager
{
public:

    /*!
     * \brief   Constructor
     * @param   graphicEngine A pointer on the graphic engine
     */
    explicit ResourceManager(GraphicEngine * graphicEngine);

    /*!
     * \brief   Return a free sprite from the graphic engine
     *          To free a sprite, setAvailable(true)
     *          To hide, hide() (~ show())
     * \return  A pointer on a free sprite
     */
    Sprite * getSprite();

private:

    /*!
     * \brief   Contains a pointer on the graphic
     *          engine to ask for sprite and text
     */
    GraphicEngine * m_graphicEngine;
};

/*!
 * \brief   Return a pointer on a free sprite
 */
inline Sprite * ResourceManager::getSprite()
{
    return m_graphicEngine->getSprite();
}

#endif // __RESOURCE_MANAGER_HPP