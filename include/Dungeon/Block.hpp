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
#include "Dungeon/BlockAttributes.hpp"

class Block
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Block(ResourceManager * resourceManager, std::string const& theme);

    /*!
     * \brief   Destructor
     */
    virtual ~Block();

    /*!
     * \brief   Initialize the block with a block
     *          attribute
     */
    void init(BlockAttributes const& attribute);

private:

    std::string m_theme;
    ResourceManager * m_resourceManager;

    uint32_t m_layerSize;
    uint32_t m_layerCount;
    uint32_t m_spriteSize;
    uint32_t m_blockWidth;
    uint32_t m_blockHeight;
    std::string m_blockName;

    char * m_rawData;
    Sprite ** m_spriteMap;
    uint32_t m_spriteMapSize;

    /*!
     * \brief   Methods section
     */
    void generateBlock();
    void getRawData(std::vector < LayerData > & layers);
    void setSprite(uint32_t layer, uint32_t offset, uint32_t index);
};

#endif // __BLOCK_HPP