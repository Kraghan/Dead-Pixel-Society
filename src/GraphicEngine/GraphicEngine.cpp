#include "GraphicEngine/GraphicEngine.hpp"

/* explicit */ GraphicEngine::GraphicEngine()
{
    // TODO
}

/* virtual */ GraphicEngine::~GraphicEngine()
{
    // TODO
}

void GraphicEngine::init(unsigned int spriteCount, unsigned int textCount)
{
    // Initializing managers
    m_spriteManager.init(spriteCount);
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
}