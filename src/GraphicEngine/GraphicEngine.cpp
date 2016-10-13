#include "GraphicEngine/GraphicEngine.hpp"

/* explicit */ GraphicEngine::GraphicEngine()
: m_window(nullptr)
, m_layerCount(0)
, m_layerSize(0)
, m_current(0)
, m_previous(0)
, m_elapsed(0)
, m_drawCounter(0)
, m_fpsPrevious(0)
, m_fpsCurrent(0)
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
    unsigned layerCount, unsigned layerSize)
{
    // Getting the manager
    m_resourceManager = resourceManager;

    // Creating window
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), name,sf::Style::Close);

    // Initializing managers
    m_spriteManager.init(spriteCount);

    // Layer information
    m_layerCount = layerCount;
    m_layerSize  = layerSize;

    // See : initLayer()
    initLayer();

    // Initializing the debug panel
    m_debugPanel.init(m_resourceManager, spriteCount, textCount);
    m_debugPanel.m_layerCount = m_layerCount;

    // Setting fps counter
    m_fpsPrevious = Clock::getCurrentTime();
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

void GraphicEngine::render()
{
    m_previous = Clock::getCurrentTime();

    // Checking the window states
    // If closed, Skipping
    if(!m_window->isOpen()) return;

    // Construct all layers
    // Assemble all drawable into those layers
    constructLayers();

    // Draw call
    // See draw()
    draw();

    // Resetting all layer's size
    // and render state
    prepareLayer();

    // Resetting info in the debug panel
    m_debugPanel.reset();
}

void GraphicEngine::constructLayers()
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
                m_layers[_sprites[index].getLayer()].append(&_sprites[index]);
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

    for(unsigned index = 0; index < m_layerCount; ++index)
    {
        // Checking size of the layer
        // Skipping if there's nothing to draw
        if(m_layers[index].getSize() == 0) continue;

        // Drawing the content of the current layer
        m_window->draw(m_layers[index].getVertices(),
                       m_layers[index].getSize(),
                       sf::Triangles,
                       m_layers[index].getState());

        m_debugPanel.m_fpsCount++;
    }

    handleTime();

    // Displaying debug panel
    m_debugPanel.draw(m_window);

    // Swapping buffers
    m_window->display();

    // Incrementing draw counter
    m_drawCounter++;
}

void GraphicEngine::handleTime()
{
    // Updating debug panel
    m_current = Clock::getCurrentTime();
    m_elapsed = m_current - m_previous;
    m_previous = m_current;

    m_debugPanel.m_renderTime = m_elapsed;

    // Checking time
    m_fpsCurrent = Clock::getCurrentTime();
    m_fpsElapsed = m_fpsCurrent - m_fpsPrevious;

    if(m_fpsElapsed >= 200)
    {
        double _fps = (m_drawCounter / (m_fpsElapsed / 200)) * 5;

        m_debugPanel.m_fps = _fps;
        m_fpsPrevious = m_fpsCurrent;
        m_drawCounter = 0;
    }
}

sf::RenderWindow * GraphicEngine::getWindow() const
{
    return m_window;
}


