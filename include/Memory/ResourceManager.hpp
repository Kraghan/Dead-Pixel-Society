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

#include "Memory/Container.hpp"
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
    inline Sprite * getSprite() {
        return m_graphicEngine->getSprite();
    }

    /*!
     * \brief   Load a texture in the texture container
     * \param   path The path of the texture to load
     * \param   alias The alias of the texture
     * \return  The pointer on the newly created texture
     */
    sf::Texture * loadTexture(std::string const& path,
                              std::string const& alias);

    /*!
     * \brief   Return the texture referenced by alias
     * \param   alias The alias (name) of the texture in the map
     * \return  A pointer on a sf::Texture or nullptr if not found
     */
    sf::Texture * getTexture(std::string const& alias);

private:

    /*!
     * \brief   Contains a pointer on the graphic
     *          engine to ask for sprite and text
     */
    GraphicEngine * m_graphicEngine;

    /*!
     * \brief   The container of sfml textures
     */
    Container < std::string, sf::Texture > m_textureContainer;
};

#endif // __RESOURCE_MANAGER_HPP