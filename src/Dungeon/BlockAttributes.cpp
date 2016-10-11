//
// Created by madjo on 11/10/2016.
//

#include "Dungeon/BlockAttributes.hpp"

BlockAttributes::BlockAttributes(std::string name, unsigned int spriteSize, unsigned int width, unsigned int height, std::vector<char> const&spriteDatas)
{
    m_name = name;
    m_spriteSize = spriteSize;
    m_width = width;
    m_height = height;
    m_spritesData = spriteDatas;
}

const std::string &BlockAttributes::getName() const {
    return m_name;
}

unsigned int BlockAttributes::getSpriteSize() const {
    return m_spriteSize;
}

unsigned int BlockAttributes::getWidth() const {
    return m_width;
}

unsigned int BlockAttributes::getHeight() const {
    return m_height;
}

const std::vector<char> &BlockAttributes::getSpritesData() const {
    return m_spritesData;
}
