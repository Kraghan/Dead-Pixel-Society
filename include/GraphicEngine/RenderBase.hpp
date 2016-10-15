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

class Sprite; ///< Forward declaration

#include <SFML/Graphics.hpp>
#include "GraphicEngine/DrawableManager.hpp"

class RenderBase
{
public:

    /*!
     * \brief   Constructor, initialize value
     */
    RenderBase();

    /*!
     * \brief   Return the wanted level of layer
     * \return  The layer level
     */
    inline int getLayer() const {
        return m_layer;
    }

    /*!
    * \brief   Return if the component is ready to be displayed
    * \return  false or true
    */
    inline bool isReady() const {
        return m_ready;
    }

    /*!
     * \brief   Return if the component is visible
     * \return  false is the component is not visible, else true
     */
    inline bool isVisible() const {
        return m_visible;
    }

    /*!
     * \brief   Set the layer level
     * \param   layer The wanted layer level
     */
    inline void setLayer(const int layer) {
        m_layer = layer;
        update();
    }

    /*!
     * \brief   Set the visible state
     * \param   visible true if visible, else false
     */
    inline void setVisible(const bool visible) {
        m_visible = visible;
        update();
    }

    /*!
     * \brief   Set the visible wireframe color
     * \param   color The color to set
     */
    inline void setWireColor(const sf::Color color) {
        m_wireColor = color;
    }

    /*!
     * \brief   Return the current color of the wireframe mode for the sprite
     * \return  The color of the wireframe mode
     */
    inline sf::Color getWireColor() const {
        return m_wireColor;
    }

protected:

    /*!
     * \brief   Allow the drawables and manages to access
     *          private function
     */
    friend class GraphicEngine;
    friend class DrawableManager<Sprite>;

    /*!
     * \brief   Return if the component is available
     * \return  false or true
     */
    inline bool isAvailable() const {
        return m_available;
    }

    /*!
     * \brief   Set the available state
     * \param   available true if available, else false
     */
    inline void setAvailable(const bool available) {
        m_available = available;
        update();
    }

private:

    /*!
     * \brief   Update the ready status of the sprite
     */
    void update();

    int m_layer;
    bool m_ready;
    bool m_visible;
    bool m_available;

    sf::Color m_wireColor;
};

#endif // __RENDER_BASE_HPP