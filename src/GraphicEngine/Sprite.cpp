#include "GraphicEngine/Sprite.hpp"

Sprite::Sprite() :
m_texture(nullptr),
m_textureRect()
{
    // None
}

Sprite::Sprite(const sf::Texture& texture) :
m_texture(nullptr),
m_textureRect()
{
    setTexture(texture);
}

Sprite::Sprite(const sf::Texture& texture, const sf::IntRect& rectangle) :
m_texture(nullptr),
m_textureRect()
{
    setTexture(texture);
    setTextureRect(rectangle);
}

void Sprite::setTexture(const sf::Texture& texture, bool resetRect)
{
    if (resetRect || (!m_texture && (m_textureRect == sf::IntRect())))
        setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

    m_texture = &texture;
}

void Sprite::setTextureRect(const sf::IntRect& rectangle)
{
    if (rectangle != m_textureRect)
    {
        m_textureRect = rectangle;
        updatePositions();
        updateTexCoords();
    }
}

const sf::Texture * Sprite::getTexture() const
{
    return m_texture;
}

const sf::IntRect& Sprite::getTextureRect() const
{
    return m_textureRect;
}

sf::FloatRect Sprite::getLocalBounds() const
{
    float width  = static_cast<float>(std::abs(m_textureRect.width));
    float height = static_cast<float>(std::abs(m_textureRect.height));

    return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect Sprite::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_texture)
    {
        states.transform *= getTransform();
        states.texture = m_texture;
        target.draw(m_vertices, 4, sf::TrianglesStrip, states);
    }
}

void Sprite::updatePositions()
{
    sf::FloatRect bounds = getLocalBounds();

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(0, bounds.height);
    m_vertices[2].position = sf::Vector2f(bounds.width, 0);
    m_vertices[3].position = sf::Vector2f(bounds.width, bounds.height);
}

void Sprite::updateTexCoords()
{
    float left   = static_cast<float>(m_textureRect.left);
    float right  = left + m_textureRect.width;
    float top    = static_cast<float>(m_textureRect.top);
    float bottom = top + m_textureRect.height;

    m_vertices[0].texCoords = sf::Vector2f(left, top);
    m_vertices[1].texCoords = sf::Vector2f(left, bottom);
    m_vertices[2].texCoords = sf::Vector2f(right, top);
    m_vertices[3].texCoords = sf::Vector2f(right, bottom);
}