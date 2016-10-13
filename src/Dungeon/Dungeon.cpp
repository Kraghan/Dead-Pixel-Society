#include "Dungeon/Dungeon.hpp"

/* explicit */ Dungeon::Dungeon(ResourceManager * resourceManager)
: m_theme("")
, m_blockCount(0)
, m_currentBlock(0)
, m_resourceManager(resourceManager)
{
    // None
}

/* virtual */ Dungeon::~Dungeon()
{
    // None
}

void Dungeon::init(std::vector< BlockAttributes * > const& blocks,
    std::string const& theme)
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
        m_blocks.push_back(Block(m_resourceManager, m_theme));

        // Buffering variables
        Block & _block = m_blocks.back();
        BlockAttributes * _attribute = blocks[index];

        // Initializing the block
        _block.init(
                _attribute->getName(),
                _attribute->getWidth(),
                _attribute->getHeight(),
                _attribute->getSpriteSize(),
                _attribute->getSpritesData()
        );

        // Hide the block
        if(index != 0) _block.hide();
    }
}
