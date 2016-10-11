//
// Created by Kraghan on 04/10/2016.
//

#include "Interface/View.hpp"

View::View(const int posX,const int posY, const unsigned int width,const unsigned int height, std::string strId)
:m_panel(posX,posY,width,height,strId)
{
    m_panel.addListener(nullptr);
}

Panel* View::getContentPane()
{
    return &m_panel;
}

void View::addListener(Listener *listener)
{
    m_panel.addListener(listener);
}

