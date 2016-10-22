#ifndef __SHAPE_HPP
#define __SHAPE_HPP

#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

#include "GraphicEngine/RenderBase.hpp"

class Shape : public sf::Drawable, public sf::Transformable, public RenderBase
{
public:

    virtual ~Shape();
    void setTexture(const sf::Texture* texture, bool resetRect = false);
    void setTextureRect(const sf::IntRect& rect);
    void setFillColor(const sf::Color& color);
    void setOutlineColor(const sf::Color& color);
    void setOutlineThickness(float thickness);
    const sf::Texture* getTexture() const;
    const sf::IntRect& getTextureRect() const;
    const sf::Color& getFillColor() const;
    const sf::Color& getOutlineColor() const;
    float getOutlineThickness() const;
    virtual std::size_t getPointCount() const = 0;
    virtual sf::Vector2f getPoint(std::size_t index) const = 0;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

    sf::Vertex * getVertices()
    {
        return &m_vertices[0];
    }

protected:

    void update();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateFillColors();
    void updateTexCoords();
    void updateOutline();
    void updateOutlineColors();

private:

    const sf::Texture* m_texture;
    sf::IntRect        m_textureRect;
    sf::Color          m_fillColor;
    sf::Color          m_outlineColor;
    float              m_outlineThickness;
    sf::VertexArray    m_vertices;
    sf::VertexArray    m_outlineVertices;
    sf::FloatRect      m_insideBounds;
    sf::FloatRect      m_bounds;
};



#endif // __SHAPE_HPP