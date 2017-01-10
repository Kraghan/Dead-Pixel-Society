#include "Player/Player.hpp"


/* explicit */ Player::Player()
: m_playerSprite(nullptr)
, m_resourceManager(nullptr)
, m_collider(nullptr)
, m_rigidbody(nullptr)
, m_state(PLAYER_STATE::IDLE)
{
    // None
}

/* virtual */ Player::~Player()
{
    // Releasing the sprite
    Sprite::release(m_playerSprite);
    Collider::release(m_collider);
    RigidBody::release(m_rigidbody);
    // TODO : Release collider and rigidbody
}

void Player::init(ResourceManager * resourceManager)
{
    m_resourceManager = resourceManager;

    // Init player physics
    m_collider = resourceManager->getCollider();
    m_collider->init(PlayerConstant::DEFAULT_X,
                     PlayerConstant::DEFAULT_Y,1,1,
                     PlayerConstant::PLAYER_SPRITE_SIZE);

    m_collider->enable();

    m_rigidbody = resourceManager->getRigidBody();

    m_rigidbody->init(PlayerConstant::DEFAULT_X,
                     PlayerConstant::DEFAULT_Y,
                     PlayerConstant::PLAYER_SPRITE_SIZE,
                     PlayerConstant::PLAYER_MASS,
                     PlayerConstant::PLAYER_ACCELARATION,
                     PlayerConstant::MAX_VELOCITY_X);

    m_rigidbody->enable();

    resourceManager->bindColliderToRigidBody(Player::Instance()->getCollider(),
                                             Player::Instance()->getRigidbody());

    // Getting the player sprite
    m_playerSprite = m_resourceManager->getSprite();
    m_playerSprite->setSmoothMotion(true);
    m_playerSprite->setRigidBody(m_rigidbody);
    m_playerSprite->setLayer(PlayerConstant::PLAYER_LAYER);
    m_playerSprite->setWireColor(sf::Color::White);

    m_animation.addState("IDLE",   AnimationState());
    m_animation.addState("RLEFT",  AnimationState());
    m_animation.addState("RRIGHT", AnimationState());
    m_animation.setState("IDLE");

    m_animation.getState("IDLE")->init(
            m_playerSprite, true,
            sf::Vector2i(0, 0), sf::Vector2i(64, 64),
            64, 1, 0.08);

    m_animation.getState("RLEFT")->init(
            m_playerSprite, true,
            sf::Vector2i(0, 64), sf::Vector2i(64, 64),
            64, 4, 0.08);

    m_animation.getState("RRIGHT")->init(
            m_playerSprite, true,
            sf::Vector2i(0, 128), sf::Vector2i(64, 64),
            64, 4, 0.08);

    // Set initial state
    m_animation.setState("IDLE");
    m_animation.start();

    // Getting his texture
    m_playerSprite->setTexture(
            *m_resourceManager->getTexture(PlayerConstant::PLAYER_SPRITE));

    // Setting the sprite attribute
    m_playerSprite->setPosition(
            PlayerConstant::DEFAULT_X*PlayerConstant::PLAYER_SPRITE_SIZE,
            PlayerConstant::DEFAULT_Y*PlayerConstant::PLAYER_SPRITE_SIZE);
}

void Player::update(double dt)
{
    m_animation.update(dt);
    m_playerSprite->setPosition(m_rigidbody->getPosition());
}

void Player::setCollider(Collider * collider)
{
    m_collider = collider;
}

void Player::setRigidbody(RigidBody * rigidBody)
{
    m_rigidbody = rigidBody;
}

Collider * Player::getCollider() const
{
    return m_collider;
}

RigidBody * Player::getRigidbody() const
{
    return m_rigidbody;
}

void Player::setState(Player::PLAYER_STATE state)
{
    m_state = state;
    switch (m_state)
    {
        case LEFT:
            m_animation.setState("RLEFT");
            m_animation.start();

            m_rigidbody->stopMovingToRight();
            m_rigidbody->startMovingToLeft();
            break;

        case RIGHT:
            m_animation.setState("RRIGHT");
            m_animation.start();

            m_rigidbody->stopMovingToLeft();
            m_rigidbody->startMovingToRight();
            break;

        case IDLE:
            m_animation.setState("IDLE");
            m_animation.start();

            m_rigidbody->stopMovingToLeft();
            m_rigidbody->stopMovingToRight();
            m_rigidbody->stopMovementX();
            break;

        default : break;
    }

}

Player::PLAYER_STATE Player::getState() const
{
    return m_state;
}

Sprite* Player::getSprite()
{
    return m_playerSprite;
}

void Player::jump()
{
    m_rigidbody->startJumping();
}

bool Player::isJumping()
{
    return m_rigidbody->isJumping();
}