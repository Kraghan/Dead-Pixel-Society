//
// Created by Kraghan on 27/09/2016.
//

#include "Interface/Component.hpp"

Component::Component(const int posX, const int posY, const int width, const int height, std::string strId)
{
    m_layer = -1;
    m_point = sf::Vector2i(posX,posY);
    m_dimension = sf::Vector2i(width,height);
    std::hash<std::string> hasher;
    m_ID = hasher(strId);
    m_pbackground = nullptr;
    m_plistener = nullptr;
    //std::cout<<"Component id : "<< m_ID <<std::endl;
}

void Component::move(const int posX, const int posY)
{
    m_point = sf::Vector2i(posX,posY);
}

void Component::move(const sf::Vector2i position)
{
    m_point = position;
}

void Component::resize(const int width, const int height)
{
    m_dimension = sf::Vector2i(width,height);
}

void Component::resize(const sf::Vector2i size)
{
    m_dimension = size;
}

const int Component::getHeight()
{
    return m_dimension.y;
}

const int Component::getWidth()
{
    return m_dimension.x;
}

const sf::Vector2i Component::getDimension()
{
    return m_dimension;
}

const int Component::getX()
{
    return m_point.x;
}

const int Component::getY()
{
    return m_point.y;
}

const sf::Vector2i Component::getPosition()
{
    return m_point;
}

void Component::setBackground(Sprite* s)
{
    m_pbackground = s;
    m_pbackground->setLayer(m_layer);
    m_pbackground->setPosition((float)getX(),(float)getY());
    //m_pbackground->setTexture(); TODO add texture in component
    m_pbackground->setTextureRect(sf::Rect<int>(getX(),getY(),getWidth(),getHeight()));
}

Sprite* Component::getBackground()
{
    return m_pbackground;
}

void Component::setLayer(int l)
{
    m_layer = l;
}

const int Component::getLayer()
{
    return m_layer;
}

const size_t Component::getID()
{
    return m_ID;
}

void Component::addListener(Listener *listener)
{
    m_plistener = listener;
}