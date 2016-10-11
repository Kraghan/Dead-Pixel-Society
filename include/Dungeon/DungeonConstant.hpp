/*!
 * \brief    File that contains all constants for dungeons
 * \file     DungeonConstant.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */

#ifndef __DUNGEON_CONSTANT_HPP
#define __DUNGEON_CONSTANT_HPP

#include <stdint.h>
#include <SFML/Graphics.hpp>

namespace constant
{
    namespace test
    {
        const char VOID_CASE = '0';
        const char WALL_CASE = '1';

        const uint32_t VOID_TEXTURE_X = 0;
        const uint32_t VOID_TEXTURE_Y = 0;

        const uint32_t WALL_TEXTURE_X = 1;
        const uint32_t WALL_TEXTURE_Y = 0;
    }
}

#endif // __DUNGEON_CONSTANT_HPP