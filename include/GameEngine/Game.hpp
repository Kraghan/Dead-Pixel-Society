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

/// Including all games states
#include "StateMachine/StateMachine.hpp"
#include "GameState/WorldMapState.hpp"
#include "GameState/DungeonState.hpp"
#include "GameState/PauseState.hpp"

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
    ResourceManager * m_resourceManager;
};

#endif // __GAME_HPP