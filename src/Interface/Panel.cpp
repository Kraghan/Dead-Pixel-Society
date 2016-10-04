//
// Created by madjo on 27/09/2016.
//

#include "Interface/Panel.hpp"

Panel::Panel(const int posX, const int posY, const unsigned int width, const unsigned int height, std::string strId)
:Component(posX,posY,width,height,strId)
{
    // TODO : Init background to none
}

void Panel::addComponent(Component component)
{
    components.push_back(component);
}

void Panel::removeComponent(Component component)
{
    //components.
}