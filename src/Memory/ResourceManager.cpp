#include "Memory/ResourceManager.hpp"
#include "GraphicEngine/GraphicEngine.hpp"

ResourceManager::ResourceManager(GraphicEngine * graphicEngine)
: m_graphicEngine(graphicEngine)
{
    // None
}

sf::Texture * ResourceManager::loadTexture(std::string const& path,
    std::string const& alias)
{
    // Allocating the resources
    sf::Texture * _texture = m_textureContainer.loadResource(alias);

    // Checking the pointer
    if(_texture == nullptr) return nullptr;

    // Loading the texture in memory
    if(!_texture->loadFromFile(path))
    {
        // Warn the user about this
        std::cerr << "Unable to load the texture ..." << std::endl;
    }

    return  _texture;
}

sf::Font * ResourceManager::loadFont(std::string const& path,
    std::string const& alias)
{
    // Allocating the resources
    sf::Font * _font = m_fontContainer.loadResource(alias);

    // Checking the pointer
    if(_font == nullptr) return nullptr;

    // Loading the texture in memory
    if(!_font->loadFromFile(path))
    {
        // Warn the user about this
        std::cerr << "Unable to load the font ..." << std::endl;
    }

    return  _font;
}

sf::Texture * ResourceManager::getTexture(std::string const& alias)
{
    return m_textureContainer.getResource(alias);
}

sf::Font *ResourceManager::getFont(std::string const &alias)
{
    return m_fontContainer.getResource(alias);
}

Sprite * ResourceManager::getSprite()
{
    return m_graphicEngine->getSprite();
}
