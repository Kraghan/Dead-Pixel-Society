/*!
 * \brief    Contains the header of the
 *           class DungeonTheme
 *
 * \file     DungeonTheme.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     15/10/2016
 */

#ifndef __DUNGEON_THEME_HPP
#define __DUNGEON_THEME_HPP

#include <string>

class DungeonTheme
{
public:

    /*!
     * \brief   Default Constructor
     */
    explicit DungeonTheme();

    /*!
     * \brief   Construct a dungeon theme
     * \param   themeKey The key of the theme
     * \param   themeName The name of the theme
     * \param   backgroundKey The key of the background
     */
    explicit DungeonTheme(std::string const& themeKey,
                          std::string const& themeName,
                          std::string backgroundKey);

    /*!
     * \brief   Destructor
     */
    virtual ~DungeonTheme();

    /*!
     * \brief   Return the key of the theme
     * \return  The key of the theme
     */
    inline std::string const& getThemeKey()
    {
        return m_themeKey;
    }

    /*!
    * \brief    Return the name of the theme
    * \return   The name of the theme
    */
    inline std::string const& getThemeName()
    {
        return m_themeName;
    }

    /*!
     * \brief   Return the background key of the theme
     * \return  The background key of the theme
     */
    inline std::string const& getBackgroundKey()
    {
        return m_backgroundKey;
    }

private:

    std::string m_themeKey;
    std::string m_themeName;
    std::string m_backgroundKey;
};

#endif // __DUNGEON_THEME_HPP