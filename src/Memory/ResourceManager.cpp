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

BlockComponent * ResourceManager::loadBlockComponent(std::string const& path,
    std::string const& alias)
{
    // Allocating the resources
    BlockComponent * _block = m_blockComponentContainer.loadResource(alias);

    // Checking the pointer
    if(_block == nullptr) return nullptr;

    // Loading the block
    BlockComponent block = m_blockParser.readFile(path);

    // Assigning value
    *_block = block;

    // Returning value
    return  _block;
}


DungeonTheme * ResourceManager::loadDungeonTheme(DungeonTheme const& theme,
    std::string const& alias)
{
    // Allocating the resources
    DungeonTheme * _theme = m_dungeonThemeContainer.loadResource(alias);

    // Checking the pointer
    if(_theme == nullptr) return nullptr;

    // Assigning value
    *_theme = theme;

    // Returning value
    return  _theme;
}

sf::Texture * ResourceManager::getTexture(std::string const& alias)
{
    return m_textureContainer.getResource(alias);
}

sf::Font * ResourceManager::getFont(std::string const& alias)
{
    return m_fontContainer.getResource(alias);
}

BlockComponent * ResourceManager::getBlockComponent(std::string const& alias)
{
    return m_blockComponentContainer.getResource(alias);
}

Sprite * ResourceManager::getSprite()
{
    return m_graphicEngine->getSprite();
}

DungeonTheme * ResourceManager::getDungeonTheme(std::string const& alias)
{
    return m_dungeonThemeContainer.getResource(alias);
}

DungeonTheme * ResourceManager::getRandomTheme()
{
    return m_dungeonThemeContainer.getRandom();
}

BlockComponent * ResourceManager::getRandomBlockComponent()
{
    return m_blockComponentContainer.getRandom();
}
