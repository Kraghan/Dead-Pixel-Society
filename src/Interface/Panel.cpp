//
// Created by Kraghan on 27/09/2016.
//

#include "Interface/Panel.hpp"

Panel::Panel(const int posX, const int posY, const unsigned int width, const unsigned int height, std::string strId)
:Component(posX,posY,width,height,strId)
{

}

void Panel::addComponent(Component* component)
{
    component->move(getX() + component->getX(), getY() + component->getY());
    m_components.push_back(component);
}

void Panel::removeComponent(Component* component)
{
    std::vector<Component*>::iterator iterator = m_components.begin();
    for(;iterator != m_components.end(); ++iterator)
    {
        if(component == *iterator) {
            m_components.erase(iterator);
            return;
        }
    }
}

void Panel::debugVector()
{
    std::cout<< "Debug vector : " << m_components.size() <<std::endl;

    for(unsigned int i = 0; i < m_components.size(); ++i)
    {
        std::cout<< " index : "<< i << "  " <<m_components[i]->getID()<<std::endl;
    }
}

void Panel::addListener(Listener* listener)
{

}

void Panel::setBackground(Sprite *s)
{

}