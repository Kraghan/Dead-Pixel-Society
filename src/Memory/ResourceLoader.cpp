#include "Memory/ResourceLoader.hpp"

/* explicit */ ResourceLoader::ResourceLoader()
{
    // None
}

/* virtual */ ResourceLoader::~ResourceLoader()
{
    // None
}

void ResourceLoader::init()
{
    // Loading fonts
    m_resources.push_back(Resource(Resource::TYPE::FONT, "RL","DEBUG_FONT"));

    // Loading blocks
    m_resources.push_back(Resource(Resource::TYPE::BLOCK, "block_1", "BLOCK_1"));
    m_resources.push_back(Resource(Resource::TYPE::BLOCK, "block_2", "BLOCK_2"));
    m_resources.push_back(Resource(Resource::TYPE::BLOCK, "block_3", "BLOCK_3"));
    m_resources.push_back(Resource(Resource::TYPE::BLOCK, "block_4", "BLOCK_4"));

    // Loading textures
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "DebugTile", "PLAYER"));
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "TileTest", "FOREST"));
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "TileTest", "BG_FOREST"));
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "DebugPanel", "DEBUG_PANEL"));
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "BackgroundForest",
                                   "BACKGROUND_FOREST"));
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "WorldMap",
                                   "WORLDMAP"));

    // Loading theme
    m_resources.push_back(Resource(Resource::TYPE::THEME,
                                   DungeonTheme("FOREST", "FOREST", "BACKGROUND_FOREST"), "FOREST"));
}

void ResourceLoader::load(ResourceManager * manager)
{
    // Loading all resources
    for(uint32_t index = 0; index < m_resources.size(); ++index)
    {
        // Buffering resource
        Resource const& _res = m_resources[index];

        switch(_res.type)
        {
            case Resource::TYPE::FONT :
            {
                manager->loadFont(_res.path, _res.alias);
                break;
            }

            case Resource::TYPE::SOUND :
            {
                // manager->loadSound(_res.path, _res.alias);
                break;
            }

            case Resource::TYPE::BLOCK :
            {
                manager->loadBlockComponent(_res.path, _res.alias);
                break;
            }

            case Resource::TYPE::THEME :
            {
                manager->loadDungeonTheme(_res.theme, _res.alias);
                break;
            }

            case Resource::TYPE::TEXTURE :
            {
                manager->loadTexture(_res.path, _res.alias);
                break;
            }

            default :
            {
                break;
            }
        }
    }
}