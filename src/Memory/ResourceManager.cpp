#include "Memory/ResourceManager.hpp"

ResourceManager::ResourceManager(GraphicEngine * graphicEngine)
: m_graphicEngine(graphicEngine)
{
    // None
}

sf::Texture * ResourceManager::loadTexture(std::string const& path,
    std::string const &alias)
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

sf::Texture * ResourceManager::getTexture(std::string const& alias)
{
    return m_textureContainer.getResource(alias);
}
