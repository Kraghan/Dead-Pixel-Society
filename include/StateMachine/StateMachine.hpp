/*!
 * \brief   Header of the state machine
 * \file    StateMachine.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __STATE_MACHINE_HPP
#define __STATE_MACHINE_HPP

#include <vector>
#include "GameEngine/Updatable.hpp"
#include "StateMachine/GameState.hpp"

class StateMachine : public Updatable
{
public:

    /*!
     * \brief   Default constr
     */
    explicit StateMachine();

    /*!
     * \brief   Destructor
     */
    virtual ~StateMachine();

    /*!
     * \brief   Implements the update method
     * \param   dt The elapsed time
     */
    virtual void update(double dt);

    /*!
     * \brief   Push a state at the top of the state machine
     * \param   pState The state to push
     */
    void pushState(GameState * pState);

    /*!
     * \brief   Remove the previous state before pushing another one
     * \param   pState The state to change with
     */
    void changeChange(GameState * pState);

    /*!
     * \brief   Remove the state at the top of the state machine
     */
    void popState();

private:

    std::vector < GameState * > m_gameStates;
};

#endif // __STATE_MACHINE_HPP
