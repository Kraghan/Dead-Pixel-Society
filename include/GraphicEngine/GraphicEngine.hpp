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
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GraphicEngine/Layer.hpp"
#include "GraphicEngine/Sprite.hpp"
#include "GraphicEngine/DebugPanel.hpp"
#include "GraphicEngine/DrawableManager.hpp"

#include "GameEngine/Clock.hpp"

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
     * \param   resourceManager The resource manager
     * \param   name The name of the window
     * \param   width The width of the window
     * \param   height The height of the window
     * \param   spriteCount The number of available sprites
     * \param   textCount The number of available texts
     */
    void init(ResourceManager * resourceManager,
            std::string const& name,
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

    /*!
    * \brief   Return a pointer on the window used by the engine
    * \return  A pointer on the window
    */
    sf::RenderWindow * getWindow() const;

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
     * \brief   The array of layers
     */
    Layer * m_layers;

    /*!
     * \brief   The sprite manager to handle
     *          the repartition of sprites
     */
    DrawableManager<Sprite> m_spriteManager;

    /*!
     * \brief   The debug panel of the graphic engine
     */
    DebugPanel m_debugPanel;

    /*!
     * \brief   Record the time to achieve a render
     */
    double m_current;
    double m_previous;
    double m_elapsed;

    uint32_t m_drawCounter;
    double m_fpsPrevious;
    double m_fpsCurrent;
    double m_fpsElapsed;

    /*!
     * \brief   A pointer on the resource manager
     */
    ResourceManager * m_resourceManager;

    /*!
     * \brief   Draw all layers
     */
    void draw();

    /*!
     * \brief   Allocates all the layers and
     *          initializes them with their size
     */
    void initLayer();

    /*!
     * \brief   Construct all layer for the future frame
     */
    void constructLayers();

    /*!
     * \brief   Prepare all layers for the next frame by
     *          resetting their size to 0
     */
    void prepareLayer();

    /*!
     * \brief   Check the elapsed time to update debug info
     */
    void handleTime();
};

#endif // __GRAPHIC_ENGINE_HPP