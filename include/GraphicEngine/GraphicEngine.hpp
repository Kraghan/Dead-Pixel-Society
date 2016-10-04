/*!
 * \brief    Contains the header of the
 *           class GraphicEngine
 *
 * \file     GraphicEngine.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     27/09/2016
 */

#ifndef __GRAPHIC_ENGINE_HPP
#define __GRAPHIC_ENGINE_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "GraphicEngine/Sprite.hpp"
#include "GraphicEngine/DrawableManager.hpp"

class GraphicEngine
{
public:

    /*!
     * \brief   Default constructor
     */
    GraphicEngine();

    /*!
     * \brief   Default destructor, free all
     *          allocated memory
     */
    virtual ~GraphicEngine();

    /*!
     * \brief   Initialize the graphic engine
     * \param   name The name of the window
     * \param   width The width of the window
     * \param   height The height of the window
     * \param   spriteCount The number of available sprites
     * \param   textCount The number of available texts
     */
    void init(std::string const& name,
            unsigned width, unsigned height,
            unsigned spriteCount, unsigned textCount,
            unsigned layerCount, unsigned layerSize);

    /*!
     * \brief   Return a free sprite
     * \return  A pointer on a engine sprite
     */
    Sprite  * getSprite();

    /*!
     * \brief   Render all graphic object referenced in the game
     */
    void render();

private:

    /*!
     * \brief   The sf window to display layers
     */
    sf::RenderWindow * m_window;

    /*!
     * \brief   Informations about layers
     */
    unsigned m_layerCount;
    unsigned m_layerSize;

    /*!
     * \brief   The sprite manager to handle
     *          the repartition of sprites
     */
    DrawableManager<Sprite> m_spriteManager;

    /*!
     * \brief   Draw all layers
     */
    void draw();
};

#endif // __GRAPHIC_ENGINE_HPP