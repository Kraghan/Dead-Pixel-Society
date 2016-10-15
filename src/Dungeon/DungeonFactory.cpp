#include "Dungeon/DungeonFactory.hpp"

/* explicit */ DungeonFactory::DungeonFactory()
: m_currentDungeon(nullptr)
, m_resourceManager(nullptr)
{
    // Initializing random
    srand((uint32_t)time(NULL));
}

/* virtual */ DungeonFactory::~DungeonFactory()
{

}

void DungeonFactory::init(ResourceManager * resourceManager)
{
    m_resourceManager = resourceManager;
}

void DungeonFactory::prepare()
{
    // Checking the old dungeon
    if(m_currentDungeon != nullptr)
    {
        delete m_currentDungeon;
        m_currentDungeon = nullptr;
    }

    // Creating the new dungeon
    m_currentDungeon = new Dungeon(m_resourceManager);
}

Dungeon * DungeonFactory::generateDungeon()
{
    // Getting a theme
    DungeonTheme * theme = randomTheme();

    // Generate the dungeon from the theme
    return generateDungeon(theme);
}

Dungeon * DungeonFactory::generateDungeon(DungeonTheme * theme)
{
    // Preparing the factory
    prepare();

    // Begin the creation pipeline
    generateStructure(theme);

    return m_currentDungeon;
}

DungeonTheme * DungeonFactory::randomTheme()
{
    // Getting theme
    DungeonTheme * theme = m_resourceManager->getRandomTheme();

    // Return the value
    return theme;
}

void DungeonFactory::generateStructure(DungeonTheme * theme)
{
    // Temporary vector
    std::vector < BlockAttributes * > _attributes;

    // Getting a size of dungeon
    uint32_t _size = rand() % DungeonRule::MAX_ROOM + DungeonRule::MIN_ROOM;

    for(uint32_t count = 0; count < _size; ++count)
    {
        _attributes.push_back((BlockAttributes *)
                &m_resourceManager->getRandomBlockComponent()->getBlockAttribute());
    }

    // Initializing the dungeon
    m_currentDungeon->init(_attributes, theme);
}