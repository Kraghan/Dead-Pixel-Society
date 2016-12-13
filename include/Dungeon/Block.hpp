/*!
 * \brief    File that contains the Block header
 * \file     Dungeon.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */

#ifndef __BLOCK_HPP
#define __BLOCK_HPP

#include <vector>
#include <string>
#include <cstring>
#include <stdint.h>

#include "GraphicEngine/Sprite.hpp"
#include "Memory/ResourceManager.hpp"

#include "Dungeon/LayerData.hpp"
#include "Dungeon/DungeonTheme.hpp"
#include "Dungeon/DungeonConstant.hpp"

class Block
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Block(ResourceManager * resourceManager, DungeonTheme * theme);

    /*!
     * \brief   Destructor
     */
    virtual ~Block();

    /*!
     * \brief   Initialize the block with a block
     *          attribute
     */
    void init(std::string const& name, uint32_t width, uint32_t height,
              uint32_t spriteSize, std::vector < LayerData > const& layerData,
              std::vector < Collider > const& colliderData);

    /*!
     * \brief   Hide the blocks
     */
    void hide();

    /*!
     * \brief   Show the blocks
     */
    void show();

    /*!
     * \brief   Load the physics
     */
    void loadPhysic();

    /*!
     * \brief   Unload the physics
     */
    void clearPhysic();

private:

    DungeonTheme * m_theme;
    ResourceManager * m_resourceManager;

    uint32_t m_spriteSize;
    uint32_t m_blockWidth;
    uint32_t m_blockHeight;
    std::string m_blockName;

    std::vector < std::vector < char > > m_rawData;
    std::vector < std::vector < Sprite * > > m_spriteMap;

    /*!
     * \brief   Generation Methods section
     */
    void generateBlock();
    void setSprite(uint32_t x, uint32_t y, uint32_t index);
    void setSpriteTextureRect(uint32_t index);
    void getRawData(std::vector < char > const& data);

    /*!
     * \brief General
     */
    void setVisible(bool visible);
};

#endif // __BLOCK_HPP