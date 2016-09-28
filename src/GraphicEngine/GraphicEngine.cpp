#include "GraphicEngine/GraphicEngine.hpp"

/* explicit */ GraphicEngine::GraphicEngine()
{
    m_textCount = 0;
    m_spriteCount = 0;

    m_spriteList = nullptr;
}

/* virtual */ GraphicEngine::~GraphicEngine()
{
    m_textCount = 0;
    m_spriteCount = 0;

    delete m_spriteList;
}

void GraphicEngine::init(uint spriteCount, uint textCount)
{
    m_textCount = textCount;
    m_spriteCount = spriteCount;

    m_spriteList = new Sprite[m_spriteCount];
}

Sprite * GraphicEngine::getSprite()
{
    return nullptr;
}

void GraphicEngine::render()
{

}