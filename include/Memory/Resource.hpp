/*!
 * \brief   Header of the Resource class
 * \file    Resource.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    14/10/2016
 */

#ifndef __RESOURCE_HPP
#define __RESOURCE_HPP

#include <string>
#include <iostream>

#include "Dungeon/DungeonTheme.hpp"

class Resource
{
public:

    enum TYPE
    {
        FONT,    ///< Represents a resource of type font
        SOUND,   ///< Represents a resource of type sound
        BLOCK,   ///< Represents a resource of type block
        THEME,   ///< Represents a resource of type theme
        TEXTURE  ///< Represents a resource of type texture
    };

    /*!
     * \brief   Construct a resource info
     * \param   _type The type of the resource
     * \param   _name The name of the file (without extension)
     * \param   _alias The alias of the file in the manager
     */
    explicit Resource(TYPE _type,
        std::string const& _name,
        std::string const& _alias);

    /*!
     * \brief   Construct a resource info
     * \param   _type The type of the resource
     * \param   _theme The theme of a dungeon
     */
    explicit Resource(TYPE _type,
        DungeonTheme const& _theme,
        std::string const& _alias);

    TYPE type;
    std::string path;
    std::string alias;
    DungeonTheme theme;

private:

    // File extension
    const std::string FONT_EXT = ".ttf";
    const std::string SOUND_EXT = ".ogg";
    const std::string BLOCK_TEXT = ".map";
    const std::string TEXTURE_EXT = ".png";

    // File path
    const std::string FONT_PATH = "../res/Font/";
    const std::string SOUND_PATH = "../res/Sound/";
    const std::string TEXTURE_PATH = "../res/Texture/";
    const std::string BLOCK_PATH = "../res/Dungeon/Block/";
};

#endif // __RESOURCE_HPP