/*!
 * \brief   Header of the class DungeonState
 * \file    DungeonState.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    18/10/2016
 */

#ifndef __DUNGEON_STATE_HPP
#define __DUNGEON_STATE_HPP

#include <PhysicEngine/PhysicEngine.hpp>
#include "GameEngine/Singleton.hpp"
#include "Memory/ResourceManager.hpp"
#include "Dungeon/DungeonFactory.hpp"

/// Include previous and next states
#include "GameState/WorldMapState.hpp"
#include "StateMachine/StateMachine.hpp"

class DungeonState : public GameState, public Singleton < DungeonState >
{
public:

    /*!
     * \brief    Constructor
     */
    explicit DungeonState();

    /*!
     * \brief     Init method
     * \param     stateMachine A pointer on the state machine
     * \param     resourceManager A pointer on the resource manager
     */
    void init(StateMachine * stateMachine, ResourceManager * resourceManager);

    /*!
     * \brief   Destructor
     */
    virtual ~DungeonState();

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
    PhysicEngine m_physicEngine;

    RigidBody* rigid;
    Sprite* test;

    Dungeon * m_dungeon;
    DungeonFactory m_dungeonFactory;
};

#endif // __DUNGEON_STATE_HPP