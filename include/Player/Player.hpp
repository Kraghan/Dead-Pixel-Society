/*!
 * \brief   Class that represents the player
 * \file    Player.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <GameEngine/Singleton.hpp>
#include "GameEngine/Updatable.hpp"
#include "Memory/ResourceManager.hpp"
#include "Player/PlayerConstant.hpp"

class Player : public Updatable, public Singleton < Player >
{
public:

    enum PLAYER_STATE
    {
        IDLE,
        RIGHT,
        LEFT
    };

    /*!
     * \brief   Default constructor
     */
    explicit Player(void);

    /*!
     * \brief   Destructor
     */
    virtual ~Player(void);

    /*!
     * \brief   Implements update method
     */
    virtual void update(double dt);

    /*!
     * \brief   Initialize the player
     * \param   resourceManager A pointer on the resource manager
     */
    void init(ResourceManager * resourceManager);

    /*!
     * \brief   m_playerSprite's getter
     */
    Sprite* getSprite(void);

    void setCollider(Collider * collider);
    void setRigidbody(RigidBody * rigidBody);

    Collider * getCollider(void) const;
    RigidBody * getRigidbody(void) const;

    void setState(Player::PLAYER_STATE state);
    Player::PLAYER_STATE getState(void) const;

    /**
     * \brief   Return true while player is in jumping phase
     */

private:

    Sprite * m_playerSprite;
    ResourceManager * m_resourceManager;

    // Physics
    Collider  * m_collider;
    RigidBody * m_rigidbody;

    // States
    PLAYER_STATE m_state;
    double m_jumpingTimeStart;
};

#endif // __PLAYER_HPP