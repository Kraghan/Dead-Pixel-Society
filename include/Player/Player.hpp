/*!
 * \brief   Class that represents the player
 * \file    Player.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/10/2016
 */

#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "GameEngine/Updatable.hpp"
#include "Memory/ResourceManager.hpp"
#include "Player/PlayerConstant.hpp"

class Player : public Updatable
{
public:

    enum PLAYER_STATE
    {
        IDLE,
        JUMP,
        RIGHT,
        LEFT
    };

    /*!
     * \brief   Default constructor
     */
    explicit Player();

    /*!
     * \brief   Destructor
     */
    virtual ~Player();

    /*!
     * \brief   Implements update method
     */
    virtual void update(double dt);

    /*!
     * \brief   Initialize the player
     * \param   resourceManager A pointer on the resource manager
     */
    void init(ResourceManager * resourceManager);

    void setCollider(Collider * collider);
    void setRigidbody(RigidBody * rigidBody);

    Collider * getCollider() const;
    RigidBody * getRigidbody() const;

    void setState(Player::PLAYER_STATE state);
    Player::PLAYER_STATE getState() const;

private:

    Sprite * m_playerSprite;
    ResourceManager * m_resourceManager;

    // Physics
    Collider  * m_collider;
    RigidBody * m_rigidbody;

    // States
    PLAYER_STATE m_state;
};

#endif // __PLAYER_HPP