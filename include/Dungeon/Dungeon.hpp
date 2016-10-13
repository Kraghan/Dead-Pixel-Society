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
    void init(std::vector < BlockAttributes * > const& blocks,
              std::string const& theme);

private:

    std::string m_theme;
    uint32_t m_blockCount;
    uint32_t m_currentBlock;

    ResourceManager * m_resourceManager;
    /*!
     * \brief   The list of blocks
     */
    std::vector < Block > m_blocks;
};

#endif // __DUNGEON_HPP