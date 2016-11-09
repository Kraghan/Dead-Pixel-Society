/*!
 * \brief   Class that contains player constants
 * \file    PlayerConstant.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __PLAYER_CONSTANT_HPP
#define __PLAYER_CONSTANT_HPP

#include <string>

class PlayerConstant
{
public:

    static const int32_t PLAYER_LAYER = 5;
    // Position of the case
    static constexpr const int DEFAULT_X = 5;
    static constexpr const int DEFAULT_Y = 0;
    static constexpr const char * PLAYER_SPRITE = "PLAYER";
    static constexpr const int PLAYER_SPRITE_SIZE = 64;

    static constexpr const float PLAYER_MASS    = 1.0f;
    static constexpr const float MAX_VELOCITY_X = 5.0f;
    static constexpr const float MAX_VELOCITY_Y = 100.0f;
    static constexpr const float PLAYER_ACCELARATION = 3.25f;
};

#endif // __PLAYER_CONSTANT_HPP