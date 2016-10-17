#include "Player/Player.hpp"


/* explicit */ Player::Player()
: m_playerSprite(nullptr)
, m_resourceManager(nullptr)
{
    // None
}

/* virtual */ Player::~Player()
{
    // Releasing the sprite
    Sprite::release(m_playerSprite);
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
