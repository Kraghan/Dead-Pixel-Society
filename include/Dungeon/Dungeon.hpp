/*!
 * \brief    File that contains the dungeon header
 * \file     Dungeon.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */

#ifndef __DUNGEON_HPP
#define __DUNGEON_HPP

#include "Dungeon/Block.hpp"
#include "Dungeon/DungeonTheme.hpp"
#include "Dungeon/BlockAttributes.hpp"

class Dungeon
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Dungeon(ResourceManager * resourceManager);

    /*!
     * \brief   Destructor
     */
    virtual ~Dungeon();

    /*!
     * \brief   Initialize the dungeon with a block attribute
     * @param   blockAttributes
     */
    void init(std::vector < BlockComponent * > const& blocks,
              DungeonTheme * theme);

    /*!
     * \brief   Change the current block for the next one
     * \return  Return false if there's no next block (end of dungeon)
     */
    bool nextBlock();

    /*!
     * \brief   Change the current block for the previous one
     * \return  Return false if there's no previous block (exit of dungeon)
     */
    bool previousBlock();

private:

    DungeonTheme * m_theme;
    uint32_t m_blockCount;
    uint32_t m_dungeonSize;
    uint32_t m_currentBlock;

    ResourceManager * m_resourceManager;

    /*!
     * \brief   The list of blocks
     */
    std::vector < Block * > m_blocks;
};

#endif // __DUNGEON_HPP