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

#include <iostream>


#include "Tool/BlockParser.hpp"
#include "Memory/Container.hpp"
#include "GraphicEngine/Sprite.hpp"
#include "GraphicEngine/ConvexShape.hpp"

#include "Dungeon/DungeonTheme.hpp"

// Forward declaration
class GraphicEngine;
class PhysicEngine;

class ResourceManager
{
public:

    /*!
     * \brief   Constructor
     * @param   graphicEngine A pointer on the graphic engine
     */
    explicit ResourceManager(GraphicEngine * graphicEngine, PhysicEngine*
    physicEngine);

    /*!
     * \brief   Return a free sprite from the graphic engine
     *          To free a sprite, setAvailable(true)
     *          To hide, hide() (~ show())
     * \return  A pointer on a free sprite
     */
    Sprite * getSprite();

    /*!
     * \brief   Return a free convex shape
     */
    ConvexShape * getConvexShape();

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

    /*!
     * \brief   Load a Font in the font container
     * \param   path The path of the font to load
     * \param   alias The alias of the font
     * \return  The pointer on the newly created font
     */
    sf::Font * loadFont(std::string const& path,
                        std::string const& alias);

    /*!
     * \brief   Return the font referenced by alias
     * \param   alias The alias (name) of the font in the map
     * \return  A pointer on a sf::Font or nullptr if not found
     */
    sf::Font * getFont(std::string const& alias);

    /*!
     * \brief   Load a BlockComponent in the block component container
     * \param   path The path of the BlockAttribute to load
     * \param   alias The alias of the BlockAttribute
     * \return  The pointer on the newly created BlockAttribute
     */
    BlockComponent * loadBlockComponent(std::string const& path,
                        std::string const& alias);

    /*!
     * \brief   Return the BlockAttribute referenced by alias
     * \param   alias The alias (name) of the BlockAttribute in the map
     * \return  A pointer on a BlockAttribute or nullptr if not found
     */
    BlockComponent * getBlockComponent(std::string const& alias);

    /*!
     * \brief   Load a DungeonTheme in the dungeon theme container
     * \param   path The path of the DungeonTheme to load
     * \param   alias The alias of the DungeonTheme
     * \return  The pointer on the newly created DungeonTheme
     */
    DungeonTheme * loadDungeonTheme(DungeonTheme const& theme,
                                    std::string const& alias);

    /*!
     * \brief   Return the DungeonTheme referenced by alias
     * \param   alias The alias (name) of the DungeonTheme in the map
     * \return  A pointer on a DungeonTheme or nullptr if not found
     */
    DungeonTheme * getDungeonTheme(std::string const& alias);

    /*!
     * \brief   Return random values
     */
    DungeonTheme * getRandomTheme();
    BlockComponent * getRandomBlockComponent();

    /*!
     * \brief   Return a free collider from the
     *          physic engine. Return nullptr if all the
     *          colliders are in use.
     */
    Collider* getCollider();

    /*!
     * \brief   Return a free rigidBody from the
     *          physic engine. Return nullptr if all the
     *          rigidBodies are in use.
     */
    RigidBody* getRigidBody();

    /*!
     * \brief   Bind a collider to a rigidBody to apply
     *          physics
     */
    void bindColliderToRigidBody(Collider* collider, RigidBody* rigidBody);

    /*!
     * \brief   Return a collider associated to the
     *          rigidBody. Return nullptr if the rigid
     *          body isn't associated to any collider
     * \param   rigidBody A pointer on the rigidbody to get the collider from
     */
    Collider * getColliderBindedToRigidBody(RigidBody* rigidBody);

    // TODO BETTER
    PhysicEngine* getPhysicEngine();

private:

    /*!
     * \brief   Contains a pointer on the graphic
     *          engine to ask for sprite and text
     */
    GraphicEngine * m_graphicEngine;

    /*!
     * \brief   The container of sfml textures, Font etc.
     */
    Container < std::string, sf::Font > m_fontContainer;
    Container < std::string, sf::Texture > m_textureContainer;
    Container < std::string, DungeonTheme > m_dungeonThemeContainer;
    Container < std::string, BlockComponent > m_blockComponentContainer;

    /*!
     * \brief   The block parser to extract block components
     */
    BlockParser m_blockParser;

    /*!
     * \brief   Contains a pointer on the physic
     *          engine to ask colliders and rigidBodies
     */
    PhysicEngine* m_physicEngine;
};

#endif // __RESOURCE_MANAGER_HPP