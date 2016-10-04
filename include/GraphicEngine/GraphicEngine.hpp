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
     * \param   spriteCount The number of available sprites
     * \param   textCount The number of available texts
     */
    void init(unsigned int spriteCount, unsigned int textCount);

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

    DrawableManager<Sprite> m_spriteManager;

    /*!
     * \brief   Draw all layers
     */
    void draw();
};

#endif // __GRAPHIC_ENGINE_HPP