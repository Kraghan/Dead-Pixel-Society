//
// Created by Kraghan on 27/09/2016.
//

#include "Interface/Component.hpp"

Component::Component(const int posX, const int posY, const int width, const int height, std::string strId)
{
    layer = -1;
    point = sf::Vector2i(posX,posY);
    dimension = sf::Vector2i(width,height);
    std::hash<std::string> hasher;
    ID = hasher(strId);
}

void Component::move(const int posX, const int posY)
{
    point = sf::Vector2i(posX,posY);
}

void Component::move(const sf::Vector2i position)
{
    point = position;
}

void Component::resize(const int width, const int height)
{
    dimension = sf::Vector2i(width,height);
}

void Component::resize(const sf::Vector2i size)
{
    dimension = size;
}

const int Component::getHeight()
{
    return dimension.y;
}

const int Component::getWidth()
{
    return dimension.x;
}

const sf::Vector2i Component::getDimension()
{
    return dimension;
}

const int Component::getX()
{
    return point.x;
}

const int Component::getY()
{
    return point.y;
}

const sf::Vector2i Component::getPosition()
{
    return point;
}

void Component::setBackground(Sprite* s)
{
    background = s;
}

Sprite* Component::getBackground()
{
    return background;
}

void Component::setLayer(int l)
{
    layer = l;
}

const int Component::getLayer()
{
    return layer;
}

const size_t Component::getID()
{
    return ID;
}