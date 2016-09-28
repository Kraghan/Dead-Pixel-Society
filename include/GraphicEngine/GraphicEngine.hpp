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

// Make a shorcut on types
typedef unsigned int uint;

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
    void init(uint spriteCount, uint textCount);

    /*!
     * \brief   Return a free sprite
     * \return  A pointer on a engine sprite
     */
    Sprite * getSprite();

    /*!
     * \brief   Render all graphic object referenced in the game
     */
    void render();

private:

    uint m_textCount;
    uint m_spriteCount;

    Sprite * m_spriteList;
};

#endif // __GRAPHIC_ENGINE_HPP