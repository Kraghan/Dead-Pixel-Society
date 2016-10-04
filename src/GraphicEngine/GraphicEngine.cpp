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
}

Sprite * GraphicEngine::getSprite()
{
    return m_spriteManager.getFreeDrawable();
}

void GraphicEngine::render()
{
    // TODO

    draw();
}

void GraphicEngine::draw()
{
    // TODO
    m_window->clear();
    m_window->display();
}
