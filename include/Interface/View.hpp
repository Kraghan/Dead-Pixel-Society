//
// Created by Kraghan on 04/10/2016.
//

#ifndef PROJECT_VIEW_H
#define PROJECT_VIEW_H


#include <vector>
#include "Interface/Component.hpp"
#include "Interface/Panel.hpp"
#include "Interface/Listener.hpp"

class View {
private:
    Panel m_panel;
public :
    View(const int posX,const int posY, const unsigned int width,const unsigned int height, std::string strId);
    Panel* getContentPane();
    void addListener(Listener* listener);
};


#endif //PROJECT_VIEW_H
