//
// Created by madjo on 27/09/2016.
//

#include "Interface/Panel.hpp"

Panel::Panel(const int posX, const int posY, const unsigned int width, const unsigned int height)
:Component(posX,posY,width,height)
{
    // TODO : Init background to none
}

void Panel::addComponent(Component component)
{
    components.push_back(component);
}

void Panel::setBackground()
{
    // TODO : setBackground
}

void Panel::removeComponent(Component component)
{
    //components.
}