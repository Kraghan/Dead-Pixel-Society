//
// Created by Kraghan on 18/10/2016.
//

#include "PhysicEngine/PhysicObjectBase.hpp"
PhysicObjectBase::PhysicObjectBase()
{
    m_id = 0;
    m_isFree = true;
    m_isReady = false;
    m_hitBox = sf::FloatRect(-1.0f,-1.0f,0.0f,0.0f);
    m_size = 0;
}

void PhysicObjectBase::init(float x, float y, float width, float height,
                            unsigned int size)
{
    m_hitBox = sf::FloatRect(x*size,y*size,width*size,height*size);
    m_size = size;
    m_isReady = true;
    m_isEnabled = false;
}

bool PhysicObjectBase::isFree()
{
    return m_isFree;
}

bool PhysicObjectBase::isReady()
{
    return m_isReady;
}

sf::Vector2f PhysicObjectBase::getPosition()const {
    return sf::Vector2f(m_hitBox.left,m_hitBox.top);
}

sf::Vector2f PhysicObjectBase::getDimension()const {
    return sf::Vector2f(m_hitBox.width,m_hitBox.height);
}

sf::FloatRect PhysicObjectBase::getHitBox()
{
    return m_hitBox;
}

unsigned int PhysicObjectBase::getSize()const {
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

unsigned int PhysicObjectBase::getId()
{
    return m_id;
}

void PhysicObjectBase::setId(unsigned int id)
{
    m_id = id;
}

void PhysicObjectBase::move(float x, float y)
{
    m_hitBox.left = x;
    m_hitBox.top = y;
}

void PhysicObjectBase::disable() {
    m_isEnabled = false;
}

void PhysicObjectBase::enable() {
    m_isEnabled= true;
}

bool PhysicObjectBase::isEnabled() {
    return m_isEnabled;
}
