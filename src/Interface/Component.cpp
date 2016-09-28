//
// Created by Kraghan on 27/09/2016.
//

#include "Interface/Component.hpp"

Component::Component(const int posX, const int posY, const unsigned int width, const unsigned int height)
{
    x = posX;
    y = posY;
    this->width = width;
    this->height = height;
}

void Component::move(const int posX, const int posY)
{
    x = posX;
    y = posY;
}

void Component::resize(const unsigned int width, const unsigned int height)
{
    this->width = width;
    this->height = height;
}

const unsigned int Component::getHeight()
{
    return height;
}

const unsigned int Component::getWidth()
{
    return width;
}

const int Component::getX()
{
    return x;
}

const int Component::getY()
{
    return y;
}