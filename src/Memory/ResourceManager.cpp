#include "Memory/ResourceManager.hpp"

ResourceManager::ResourceManager(GraphicEngine * graphicEngine)
: m_graphicEngine(graphicEngine)
{
    // None
}

Sprite * ResourceManager::getSprite()
{
    return m_graphicEngine.getSprite();
}
