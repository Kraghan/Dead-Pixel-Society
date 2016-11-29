#include "GraphicEngine/GraphicEngine.hpp"

/*!
 * static
 */
Sprite * GraphicEngine::background = nullptr;

/* explicit */ GraphicEngine::GraphicEngine()
: m_window(nullptr)
, m_layerCount(0)
, m_layerSize(0)
, m_framerate(60.0)
, m_delta(0.0)
, m_current(0.0)
, m_previous(0.0)
, m_elapsed(0.0)
, m_drawCounter(0)
, m_fpsPrevious(0.0)
, m_fpsCurrent(0.0)
, m_fpsElapsed(0.0)
, m_currentRender(0.0)
, m_previousRender(0.0)
, m_elapsedRender(0.0)
, m_renderLag(0.0)
, m_wireframe(false)
, m_resourceManager(nullptr)
{
    // None
}

/* virtual */ GraphicEngine::~GraphicEngine()
{
    // Deleting window
    delete m_window;

    // Deleting layers
    delete [] m_layers;
}

void GraphicEngine::init(ResourceManager * resourceManager,
    std::string const& name,
    unsigned width, unsigned height,
    unsigned spriteCount, unsigned textCount,
    unsigned shapeCount,
    unsigned layerCount, unsigned layerSize)
{
    // Getting the manager
    m_resourceManager = resourceManager;

    // Creating window
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), name,sf::Style::Close);

    // Initializing managers
    m_spriteManager.init(spriteCount);
    m_shapeManager.init(shapeCount);

    // Layer information
    m_layerCount = layerCount;
    m_layerSize  = layerSize;

    // See : initLayer()
    initLayer();

    // Initializing the debug panel
    m_debugPanel.init(m_resourceManager, spriteCount, textCount);
    m_debugPanel.m_layerCount = m_layerCount;

    // Initializing the physic debug interface
    m_drawPhysics.init(m_resourceManager);

    // Setting fps counter
    m_fpsPrevious = m_clock.getElapsedTime().asSeconds();

    // Computing delta
    m_delta = 1 / m_framerate;

    // Setting time
    m_previousRender = m_clock.getElapsedTime().asSeconds();
}

void GraphicEngine::initLayer()
{
    // Allocating layers
    m_layers = new Layer[m_layerCount];

    // Initializing layers
    for(unsigned i = 0; i < m_layerCount; ++i)
    {
        m_layers[i].init(m_layerSize);
    }
}

Sprite * GraphicEngine::getSprite()
{
    return m_spriteManager.getFreeDrawable();
}

ConvexShape * GraphicEngine::getConvexShape()
{
    return m_shapeManager.getFreeDrawable();
}

void GraphicEngine::render(double factor)
{
    // Checking if its the time to render
    m_currentRender = m_clock.getElapsedTime().asSeconds();
    m_elapsedRender = m_currentRender - m_previousRender;

    m_previousRender = m_currentRender;
    m_renderLag += m_elapsedRender;

    if(m_renderLag < m_delta)
    {
        // It's not yet the time to render
        // Skipping draw frame
        return;
    }

    // It's time to draw
    m_renderLag -= m_delta;

    // Getting time
    m_previous = m_clock.getElapsedTime().asSeconds();

    // Checking the window states
    // If closed, Skipping
    if(!m_window->isOpen()) return;

    // Construct all layers
    // Assemble all drawable into those layers
    constructLayers(factor);

    // Draw call
    // See draw()
    draw();

    // Resetting all layer's size
    // and render state
    prepareLayer();

    // Resetting info in the debug panel
    m_debugPanel.reset();
}

void GraphicEngine::constructLayers(double factor)
{
    // Getting sprites list
    const Sprite * _sprites = m_spriteManager.getDrawableList();
    unsigned _spritesCount  = m_spriteManager.getDrawableCount();

    // Iterating the list
    for(unsigned index = 0; index < _spritesCount; ++index)
    {
        // Extracting info
        if(!_sprites[index].isAvailable()) m_debugPanel.m_spriteInUse++;

        // The sprite is in use
        // So we can add him to a layer
        if(_sprites[index].isReady())
        {
            // Checking layer index
            if(_sprites[index].getLayer() < (int)m_layerCount)
            {
                // The sprite is conform
                // We can append it to his target layer
                m_layers[_sprites[index].getLayer()].append(&_sprites[index], factor);
            }
        }
    }

    // Getting text list
    const ConvexShape * _shapes = m_shapeManager.getDrawableList();
    unsigned _shapeCount        = m_shapeManager.getDrawableCount();

    // Iterating the list
    for(unsigned index = 0; index < _shapeCount; ++index)
    {
        // The sprite is in use
        // So we can add him to a layer
        if(_shapes[index].isReady())
        {
            // Checking layer index
            if(_shapes[index].getLayer() < (int)m_layerCount)
            {
                // The sprite is conform
                // We can append it to his target layer
                m_layers[_shapes[index].getLayer()].append(&_shapes[index], factor);
            }
        }
    }

    for(uint32_t i = 0; i < m_layerCount; ++i)
    {
        m_debugPanel.m_appendSkipped += m_layers[i].getSkipped();
    }
}

void GraphicEngine::prepareLayer()
{
    for(unsigned index = 0; index < m_layerCount; ++index)
    {
        // Prepare the layer
        m_layers[index].prepare();
    }
}

void GraphicEngine::draw()
{
    // Clearing buffer
    m_window->clear();

    // Drawing background
    if(GraphicEngine::background != nullptr)
    {
        m_window->draw(*GraphicEngine::background);
    }

    for(unsigned index = 0; index < m_layerCount; ++index)
    {
        // Checking size of the layer
        // Skipping if there's nothing to draw
        if(m_layers[index].getSize() == 0) continue;

        // Drawing the content of the current layer
        m_window->draw(m_layers[index].getVertices(),
                       m_layers[index].getSize(),
                       m_layers[index].getPrimitive(),
                       m_layers[index].getState());

        m_debugPanel.m_fpsCount++;
    }

    handleTime();

    // Displaying debug panel
    m_debugPanel.draw(m_window);

    // Displaying physic debug interface
    m_drawPhysics.draw(m_window);

    // Swapping buffers
    m_window->display();

    // Incrementing draw counter
    m_drawCounter++;
}

void GraphicEngine::handleTime()
{
    // Updating debug panel
    m_current = m_clock.getElapsedTime().asSeconds();
    m_elapsed = m_current - m_previous;
    m_previous = m_current;

    m_debugPanel.m_renderTime = m_elapsed;

    // Checking time
    m_fpsCurrent = m_clock.getElapsedTime().asSeconds();
    m_fpsElapsed = m_fpsCurrent - m_fpsPrevious;

    if(m_fpsElapsed >= 1.0)
    {
        double _fps = (m_drawCounter / (m_fpsElapsed / 0.2)) * 5.0;

        m_debugPanel.m_fps = _fps;
        m_fpsPrevious = m_fpsCurrent;
        m_drawCounter = 0;
    }
}

sf::RenderWindow * GraphicEngine::getWindow() const
{
    return m_window;
}

void GraphicEngine::wireframe(bool state)
{
    m_wireframe = state;

    for(uint32_t i = 0; i < m_layerCount; ++i)
    {
        m_layers[i].setWireframe(state);
    }
}

void GraphicEngine::setFramerate(double framerate)
{
    m_framerate = framerate;

    // Re-computing delta (time step)
    m_delta = 1 / m_framerate;
}

void GraphicEngine::toggleWireframe()
{
    m_wireframe = !m_wireframe;

    for(uint32_t i = 0; i < m_layerCount; ++i)
    {
        m_layers[i].setWireframe(m_wireframe);
    }
}

void GraphicEngine::toggleWireframe(uint32_t layer)
{
    if(layer >= m_layerCount) return;
    m_layers[layer].setWireframe(!m_layers[layer].getWireframe());
}

