#include "Dungeon/DungeonFactory.hpp"
#include "GraphicEngine/GraphicEngine.hpp"

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

    // Hiding background
    Sprite * _sprite = GraphicEngine::background;
    if(_sprite  != nullptr) _sprite->setVisible(false);

    // Generate the dungeon from the theme
    return generateDungeon(theme);
}

Dungeon * DungeonFactory::generateDungeon(DungeonTheme * theme)
{
    // Preparing the factory
    prepare();

    // Begin the creation pipeline
    generateStructure(theme);

    // Setting the background
    Sprite * _sprite = GraphicEngine::background;
    if(_sprite == nullptr)
    {
        _sprite = m_resourceManager->getSprite();
        GraphicEngine::background = _sprite;
    }

    _sprite->setVisible(true);
    _sprite->setPosition(0.0f, 0.0f);
    _sprite->setTexture(*(m_resourceManager->getTexture(theme->getBackgroundKey())));

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
    std::vector < BlockComponent * > _attributes;

    // Getting a size of dungeon
    uint32_t _size = rand() % DungeonRule::MAX_ROOM + DungeonRule::MIN_ROOM;

    for(uint32_t count = 0; count < _size; ++count)
    {
        _attributes.push_back(m_resourceManager->getRandomBlockComponent());
    }

    // Initializing the dungeon
    m_currentDungeon->init(_attributes, theme);
}