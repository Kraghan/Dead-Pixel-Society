/*!
 * \brief    Contains the header of the
 *           class Sprite
 *
 * \file     Sprite.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     25/09/2016
 */

#ifndef __SPRITE_HPP
#define __SPRITE_HPP

#include <SFML/Graphics.hpp>
#include "GraphicEngine/RenderBase.hpp"

class Sprite : public sf::Drawable, public sf::Transformable, public RenderBase
{
public:

    /*!
     * \brief 	Default constructor
     */
    Sprite();

    /*!
     * \brief 	Construct a sprite from a texture
     * \param 	texture A const reference on the texture
     */
    explicit Sprite(const sf::Texture& texture);

    /*!
     * \brief 	Construct a sprite from a texture and its texture rect
     * \param 	texture A const reference on the texture
     * \param	rectangle A const reference on the rectangle
     */
    Sprite(const sf::Texture& texture, const sf::IntRect& rectangle);

    /*!
     * \brief 	Set the texture if the sprite
     * \param 	texture A const reference on the texture
     * \param	resetRect A default parameter to reset the texture rect
     */
    void setTexture(const sf::Texture& texture, bool resetRect = false);

    /*!
     * \brief 	Set the texture rect
     * \param 	rectangle The texture rect
     */
    void setTextureRect(const sf::IntRect& rectangle);

    /*!
     * \brief	Return a const pointer on the texture
     */
    const sf::Texture* getTexture() const;

    /*!
     * \brief 	Return a const reference on the texture rect
     */
    const sf::IntRect& getTextureRect() const;

    /*!
	 * \brief 	Return the local coordinate of the entity
	 */
    sf::FloatRect getLocalBounds() const;

    /*!
     * \brief 	Return the global coordinate of the entity
     */
    sf::FloatRect getGlobalBounds() const;

private:

    /*!
     * \brief Draw the sprite to a render target
     * \param target Render target to draw to
     * \param states Current render states
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*!
     * \brief 	Update vertices position
     */
    void updatePositions();

    /*!
     * \brief 	Update texture coordinates
     */
    void updateTexCoords();

    const sf::Texture* m_texture;
    sf::Vertex         m_vertices[4];
    sf::IntRect        m_textureRect;
};

#endif // __SPRITE_HPP

