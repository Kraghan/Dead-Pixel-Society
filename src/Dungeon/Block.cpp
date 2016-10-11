#include "Dungeon/Block.hpp"

/* explicit */ Block::Block()
: m_spriteSize(0)
, m_blockWidth(0)
, m_blockHeight(0)
, m_blockName("UNDEFINED")
, m_spriteMap(nullptr)
, m_rawData(nullptr)
{
    // None
}

/* virtual */ Block::~Block()
{
    // None
}

void Block::init(/* BlockAttribute * attribute */)
{
    // TODO
}
