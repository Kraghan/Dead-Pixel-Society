/*!
 * \brief   Header of the class PauseState
 * \file    PauseState.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    18/10/2016
 */

#ifndef __PAUSE_STATE_HPP
#define __PAUSE_STATE_HPP

#include "GameEngine/Singleton.hpp"
#include "Memory/ResourceManager.hpp"

/// Include previous and next states
#include "StateMachine/StateMachine.hpp"

class PauseState : public GameState, public Singleton < PauseState >
{
public:

    /*!
     * \brief    Constructor
     */
    explicit PauseState();

    /*!
     * \brief     Init method
     * \param     stateMachine A pointer on the state machine
     * \param     resourceManager A pointer on the resource manager
     */
    void init(StateMachine * stateMachine, ResourceManager * resourceManager);

    /*!
     * \brief   Destructor
     */
    virtual ~PauseState();

    /*!
     * \brief   Function called when a state is pushed
     * \return  True if the state can be pushed
     */
    virtual bool onEnter();

    /*!
     * \brief   Function called when a state is popped
     * \return  True if the state can be popped
     */
    virtual bool onExit();

    /*!
     * \brief   Implementing update methods
     * \param   The elapsed time since last update
     */
    virtual void update(double dt);

private:

    StateMachine * m_stateMachine;
    ResourceManager * m_resourceManager;
};

#endif // __PAUSE_STATE_HPP