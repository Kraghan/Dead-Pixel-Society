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

private:

    uint32_t m_spriteSize;
    uint32_t m_blockWidth;
    uint32_t m_blockHeight;
    std::string m_blockName;



};

#endif // __BLOCK_HPP