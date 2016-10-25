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
    static constexpr const float DEFAULT_X = 64.0f;
    static constexpr const float DEFAULT_Y = 640.0f;
    static constexpr const char * PLAYER_SPRITE = "PLAYER";

    static constexpr const float PLAYER_MASS    = 80.0f;
    static constexpr const float MAX_VELOCITY_X = 10.0f;
    static constexpr const float MAX_VELOCITY_Y = 100.0f;
};

#endif // __PLAYER_CONSTANT_HPP