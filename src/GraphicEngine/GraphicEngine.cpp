#include "GraphicEngine/GraphicEngine.hpp"

/* explicit */ GraphicEngine::GraphicEngine()
: m_window(nullptr)
, m_layerCount(0)
, m_layerSize(0)
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

void GraphicEngine::init(std::string const& name,
    unsigned width, unsigned height,
    unsigned spriteCount, unsigned textCount,
    unsigned layerCount, unsigned layerSize)
{
    // Creating window
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), name);

    // Initializing managers
    m_spriteManager.init(spriteCount);

    // Layer information
    m_layerCount = layerCount;
    m_layerSize  = layerSize;

    // See : initLayer()
    initLayer();
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
}

void GraphicEngine::constructLayers()
{
    // Getting sprites list
    const Sprite * _sprites = m_spriteManager.getDrawableList();
    unsigned _spritesCount  = m_spriteManager.getDrawableCount();

    // Iterating the list
    for(unsigned index = 0; index < _spritesCount; ++index)
    {
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
    }

    // Swapping buffers
    m_window->display();
}

sf::RenderWindow *GraphicEngine::getWindow() const
{
    return m_window;
}
