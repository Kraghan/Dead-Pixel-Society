#include "Memory/Resource.hpp"

Resource::Resource(Resource::TYPE _type,
    DungeonTheme const& _theme,
    std::string const& _alias)
{
    type = _type;
    alias = _alias;
    theme = _theme;
}


Resource::Resource(Resource::TYPE _type,
    std::string const& _name,
    std::string const& _alias)
{
    type = _type;
    alias = _alias;

    switch(type)
    {
        case Resource::FONT :
        {
            path = FONT_PATH + _name + FONT_EXT;
            break;
        }

        case Resource::SOUND :
        {
            path = SOUND_PATH + _name + SOUND_EXT;
            break;
        }

        case Resource::BLOCK :
        {
            path = BLOCK_PATH + _name + BLOCK_TEXT;
            break;
        }

        case Resource::TEXTURE :
        {
            path = TEXTURE_PATH + _name + TEXTURE_EXT;
            break;
        }

        default :
        {
            std::cerr << "Type not supported ..." << std::endl;
            break;
        }
    }
}
