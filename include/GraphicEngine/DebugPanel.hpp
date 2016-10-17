/*!
 * \brief    Contains the header of the
 *           class DebugPanel
 *
 * \file     DebugPanel.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     13/10/2016
 */

#ifndef __DEBUG_PANEL_HPP
#define __DEBUG_PANEL_HPP

#include <stdint.h>
#include <SFML/Graphics.hpp>
#include "GraphicEngine/Sprite.hpp"
#include "GraphicEngine/GraphicConstant.hpp"

#include "Tool/Patch.hpp"
#include "Memory/ResourceManager.hpp"

class DebugPanel
{
public:

    /*!
     * \brief   Constructor
     */
    explicit DebugPanel();

    /*!
     * \brief   Destructor
     */
    virtual ~DebugPanel();

    /*!
     * \brief   Initialize the debug panel
     * \param   resourceManager A pointer on the resource manager
     */
    void init(ResourceManager * resourceManager,
              uint32_t spriteCount, uint32_t textCount);

    /*!
     * \brief   Reset data for the  next frame
     */
    void reset();

    /*!
     * \brief       Draw the debug panel
     * \deprecated  Use the legacy draw for the moment
     */
    void draw(sf::RenderWindow * window);

    /*!
     * \brief   Debug information
     */
    double m_fps;
    double m_delta;
    double m_renderTime;
    uint32_t m_fpsCount;
    uint32_t m_textInUse;
    uint32_t m_layerCount;
    uint32_t m_spriteInUse;
    uint32_t m_appendSkipped;

private:

    Sprite * m_panel;
    ResourceManager * m_resourceManager;
    std::vector < sf::Text > m_information;

    uint32_t m_spriteCount;
    uint32_t m_textCount;

    /*!
     * \brief   Set the string in each text
     */
    void setTextContent();
};

#endif // __DEBUG_PANEL_HPP