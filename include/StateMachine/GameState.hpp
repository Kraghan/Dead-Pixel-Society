/*!
 * \brief   Header of the game state
 * \file    StateMachine.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __GAME_STATE_HPP
#define __GAME_STATE_HPP

#include "GameEngine/Updatable.hpp"

class GameState : public Updatable
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit GameState();

    /*!
     * \brief   Destructor
     */
    virtual ~GameState();

    /*!
     * \brief   Function called when a state is pushed
     * \return  True if the state can be pushed
     */
    virtual bool onEnter() = 0;

    /*!
     * \brief   Function called when a state is popped
     * \return  True if the state can be popped
     */
    virtual bool onExit() = 0;
};

#endif // __GAME_STATE_HPP