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

class Dungeon
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Dungeon();

    /*!
     * \brief   Destructor
     */
    virtual ~Dungeon();

private:

    /*!
     * \brief   The block count of
     *          the dungeon, see Block.hpp
     */
    uint32_t m_blockCount;
};

#endif // __DUNGEON_HPP