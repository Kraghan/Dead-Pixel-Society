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

    // Loading textures
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "TileTest", "FOREST"));
    m_resources.push_back(Resource(Resource::TYPE::TEXTURE, "DebugPanel", "DEBUG_PANEL"));
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