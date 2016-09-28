/*!
 * \brief    Contains the header of the
 *           class RenderBase
 *
 * \file     RenderBase.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     25/09/2016
 */

#ifndef __RENDER_BASE_HPP
#define __RENDER_BASE_HPP

#include <SFML/Graphics.hpp>

class RenderBase
{
public:

    virtual sf::Vertex * getVertices() = 0;

private:

    int m_layer;
    bool m_isVisible;
    bool m_available;
};

#endif // __RENDER_BASE_HPP