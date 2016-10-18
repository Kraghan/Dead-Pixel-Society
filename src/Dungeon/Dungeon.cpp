#include "Dungeon/Dungeon.hpp"

/* explicit */ Dungeon::Dungeon(ResourceManager * resourceManager)
: m_theme(nullptr)
, m_blockCount(0)
, m_dungeonSize(0)
, m_currentBlock(0)
, m_resourceManager(resourceManager)
{
    // None
}

/* virtual */ Dungeon::~Dungeon()
{
    for(uint32_t index = 0; index < m_blocks.size(); ++index)
    {
        delete m_blocks[index];
    }
}

void Dungeon::init(std::vector< BlockAttributes * > const& blocks,
    DungeonTheme * theme)
{
    // Initializing values to default
    m_theme = theme;
    m_blockCount = blocks.size();
    m_currentBlock = 0;

    // Clearing the old vector
    m_blocks.clear();

    // Iterating the blocks and creating them
    for(uint32_t index = 0; index < blocks.size(); ++index)
    {
        // Creating the block
        m_blocks.push_back(new Block(m_resourceManager, m_theme));

        // Buffering variables
        Block * _block = m_blocks.back();
        BlockAttributes * _attribute = blocks[index];

        // Initializing the block
        _block->init(
                _attribute->getName(),
                _attribute->getWidth(),
                _attribute->getHeight(),
                _attribute->getSpriteSize(),
                _attribute->getSpritesData()
        );

        // Hide the block
        if(index != 0)
        {
            _block->hide();
        }

        m_dungeonSize++;
    }
}

bool Dungeon::nextBlock()
{
    // The dungeon is over !
    if(m_currentBlock + 1 >= m_dungeonSize)
    {
        m_blocks[m_currentBlock]->hide();
        return false;
    }

    // There is a next block
    // Hiding the current block
    m_blocks[m_currentBlock]->hide();

    // Incrementing the current block
    m_currentBlock++;

    // Showing the next one
    m_blocks[m_currentBlock]->show();

    return false;
}

bool Dungeon::previousBlock()
{
    // The player wants to go out
    if(m_currentBlock - 1 < 0)
    {
        m_blocks[m_currentBlock]->hide();
        return false;
    }

    // There is a next block
    // Hiding the current block
    m_blocks[m_currentBlock]->hide();

    // Decrementing the current block
    m_currentBlock--;

    // Showing the previous one
    m_blocks[m_currentBlock]->show();

    return false;
}
