#include "Dungeon/DungeonTheme.hpp"

/* explicit */ DungeonTheme::DungeonTheme()
{
    // None
}

/* explicit */ DungeonTheme::DungeonTheme(std::string const &themeKey,
    std::string const &themeName, std::string backgroundKey)
: m_themeKey(themeKey)
, m_themeName(themeName)
, m_backgroundKey(backgroundKey)
{
    // None
}

/* virtual */DungeonTheme::~DungeonTheme()
{
    // None
}
