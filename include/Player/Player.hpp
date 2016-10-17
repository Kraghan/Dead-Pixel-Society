/*!
 * \brief   Class that represents the player
 * \file    Player.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "Memory/ResourceManager.hpp"
#include "Player/PlayerConstant.hpp"

class Player
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Player();

    /*!
     * \brief   Destructor
     */
    virtual ~Player();

    /*!
     * \brief   Initialize the player
     * \param   resourceManager A pointer on the resource manager
     */
    void init(ResourceManager * resourceManager);

private:

    Sprite * m_playerSprite;
    ResourceManager * m_resourceManager;
};

#endif // __PLAYER_HPP