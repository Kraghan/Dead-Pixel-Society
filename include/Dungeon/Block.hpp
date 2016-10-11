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
#include <stdint.h>
#include <GraphicEngine/Sprite.hpp>

class Block
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Block();

    /*!
     * \brief   Destructor
     */
    virtual ~Block();

    /*!
     * \brief   Initialize the block with a block
     *          attribute
     */
    void init(/*BlockAttribute * attribute */);

private:

    uint32_t m_spriteSize;
    uint32_t m_blockWidth;
    uint32_t m_blockHeight;
    std::string m_blockName;

    Sprite * m_spriteMap;
    unsigned char * m_rawData;
};

#endif // __BLOCK_HPP