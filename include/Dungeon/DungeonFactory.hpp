/*!
 * \brief   Header of the class Dungeon factory
 * \file    DungeonFacory.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    15/09/2016
 */

#ifndef __DUNGEON_FACTORY_HPP
#define __DUNGEON_FACTORY_HPP

#include "Dungeon/Dungeon.hpp"
#include "Dungeon/DungeonRule.hpp"
#include "Memory/ResourceManager.hpp"

class DungeonFactory
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit DungeonFactory();

    /*!
     * \brief   Destructor
     */
    virtual ~DungeonFactory();

    /*!
     * \brief   Initialize the dungeon factory
     * \param   resourceManager A pointer on the resource manager
     */
    void init(ResourceManager * resourceManager);

    /*!
     * \brief   Generate a dungeon from the dungeon rule
     * \return  Return a new generated dungeon
     */
    Dungeon * generateDungeon();
    Dungeon * generateDungeon(DungeonTheme * theme);

private:

    Dungeon * m_currentDungeon;
    ResourceManager * m_resourceManager;

    /*!
     * \brief   Prepare the factory to create a dungeon
     */
    void prepare();

    /*!
     * \brief   Get a random theme for the dungeon
     * \brief   The choosen theme
     */
    DungeonTheme * randomTheme();

    /*!
     * \brief   Method for the creation pipeline
     */
    void generateStructure(DungeonTheme * theme);
};

#endif // __DUNGEON_FACTORY_HPP