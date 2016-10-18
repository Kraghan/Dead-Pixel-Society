//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/PhysicObjectBase.hpp"
PhysicObjectBase::PhysicObjectBase()
{
    m_isFree = true;
    m_isReady = false;
    m_hitBox = sf::IntRect(-1,-1,0,0);
    m_size = 0;
}

void PhysicObjectBase::init(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int size)
{
    m_hitBox = sf::IntRect(x,y,width,height);
    m_size = size;
    m_isReady = true;
}

bool PhysicObjectBase::isFree()
{
    return m_isFree;
}

sf::Vector2i PhysicObjectBase::getPosition()
{
    return sf::Vector2i(m_hitBox.left,m_hitBox.top);
}

sf::Vector2u PhysicObjectBase::getDimension()
{
    return sf::Vector2u((unsigned int)m_hitBox.width,(unsigned int)m_hitBox.height);
}

sf::IntRect PhysicObjectBase::getHitBox()
{
    return m_hitBox;
}

unsigned int PhysicObjectBase::getSize()
{
    return m_size;
}

void PhysicObjectBase::setUsed()
{
    m_isFree = false;
}

void PhysicObjectBase::setFree()
{
    m_isFree = true;
    m_isReady = false;
}