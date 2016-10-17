/*!
 * \brief   Main class of the game
 * \file    Game.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    24/09/2016
 */

#ifndef __GAME_HPP
#define __GAME_HPP

#include "GameEngine/Updatable.hpp"
#include "Memory/ResourceManager.hpp"

// TMP
#include "Player/Player.hpp"
#include "Dungeon/DungeonFactory.hpp"
// TMP

#include "StateMachine/StateMachine.hpp"

class Game : public Updatable
{
public:

    /*!
     * \brief   Constructor
     */
    explicit Game();

    /*!
     * \brief   Destructor
     */
    virtual ~Game();

    /*!
     * \brief   Initialize the game
     */
    void init(ResourceManager * resourceManager);

    /*!
     * \brief   Update the game with dt
     * \param   dt The elpased time
     */
    virtual void update(double dt);

private:

    StateMachine m_stateMachine;

    // TMP
    Player m_player;
    Dungeon * m_dungeon;
    DungeonFactory m_dungeonFactory;
    // TMP

    ResourceManager * m_resourceManager;
};

#endif // __GAME_HPP