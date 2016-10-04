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

    /*!
     * \brief   Constructor, initialize value
     */
    RenderBase();

    /*!
     * \brief   Return the wanted level of layer
     * \return  The layer level
     */
    int  getLayer() const;

    /*!
    * \brief   Return if the component is ready to be displayed
    * \return  false or true
    */
    bool isReady() const;

    /*!
     * \brief   Return if the component is visible
     * \return  false is the component is not visible, else true
     */
    bool isVisible() const;

    /*!
     * \brief   Return if the component is available
     * \return  false or true
     */
    bool isAvailable() const;

    /*!
     * \brief   Set the layer level
     * \param   layer The wanted layer level
     */
    void setLayer(const int layer);

    /*!
     * \brief   Set the visible state
     * \param   visible true if visible, else false
     */
    void setVisible(const bool visible);

    /*!
     * \brief   Set the available state
     * \param   available true if available, else false
     */
    void setAvailable(const bool available);

private:

    int m_layer;
    bool m_ready;
    bool m_visible;
    bool m_available;

    void update();
};

inline int RenderBase::getLayer() const {
    return m_layer;
}

inline bool RenderBase::isReady() const {
    return m_ready;
}

inline bool RenderBase::isVisible() const {
    return m_visible;
}

inline bool RenderBase::isAvailable() const {
    return m_available;
}

inline void RenderBase::setLayer(const int layer) {
    m_layer = layer;
    update();
}

inline void RenderBase::setVisible(const bool visible) {
    m_visible = visible;
    update();
}

inline void RenderBase::setAvailable(const bool available) {
    m_available = available;
    update();
}

#endif // __RENDER_BASE_HPP