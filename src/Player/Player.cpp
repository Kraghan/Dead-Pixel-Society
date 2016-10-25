#include "Player/Player.hpp"


/* explicit */ Player::Player()
: m_playerSprite(nullptr)
, m_resourceManager(nullptr)
, m_rigidbody(nullptr)
, m_collider(nullptr)
, m_state(PLAYER_STATE::IDLE)
{
    // None
}

/* virtual */ Player::~Player()
{
    // Releasing the sprite
    Sprite::release(m_playerSprite);

    // TODO : Release collider and rigidbody
}

void Player::init(ResourceManager * resourceManager)
{
    m_resourceManager = resourceManager;

    // Getting the player sprite
    m_playerSprite = m_resourceManager->getSprite();

    // Getting his texture
    m_playerSprite->setTexture(
            *m_resourceManager->getTexture(PlayerConstant::PLAYER_SPRITE));

    // Setting the sprite attribute
    m_playerSprite->setPosition(
            PlayerConstant::DEFAULT_X,
            PlayerConstant::DEFAULT_Y);

    m_playerSprite->setLayer(PlayerConstant::PLAYER_LAYER);
    m_playerSprite->setWireColor(sf::Color::White);
}


void Player::update(double dt)
{
    // TODO
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
}

Player::PLAYER_STATE Player::getState() const
{
    return m_state;
}