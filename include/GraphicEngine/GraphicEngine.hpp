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
#include "GraphicEngine/ConvexShape.hpp"
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
            unsigned shapeCount,
            unsigned layerCount, unsigned layerSize);

    /*!
     * \brief   Return a free sprite
     * \return  A pointer on a engine sprite
     */
    Sprite  * getSprite();

    /*!
     * \brief   Return a free convex shape
     * @return  A pointer on a engine shape
     */
    ConvexShape * getConvexShape();

    /*!
     * \brief   Render all graphic object referenced in the game
     */
    void render(double factor);

    /*!
    * \brief   Return a pointer on the window used by the engine
    * \return  A pointer on the window
    */
    sf::RenderWindow * getWindow() const;

    /*!
     * \brief   Set the wireframe mode
     * \param   state true to activate, false to disabled
     */
    void wireframe(bool state);

    /*!
     * \brief   Set the framerate of the engine
     * \param   framerate The target framerate
     */
    void setFramerate(double framerate);

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
    DrawableManager<ConvexShape> m_shapeManager;

    /*!
     * \brief   The debug panel of the graphic engine
     */
    DebugPanel m_debugPanel;

    /*!
     * \brief   The framerate of the game
     */
    double m_framerate;
    double m_delta;

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

    double m_currentRender;
    double m_previousRender;
    double m_elapsedRender;
    double m_renderLag;

    /*!
     * \brief   When true, display the game in wireframe !
     */
    bool m_wireframe;

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