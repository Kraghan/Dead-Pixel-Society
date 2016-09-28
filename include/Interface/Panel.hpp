//
// Created by madjo on 27/09/2016.
//

#ifndef PROJECT_PANEL_H
#define PROJECT_PANEL_H

#include <vector>

#include "Component.hpp"

class Panel : public Component{
public:
    explicit Panel(const int posX,const int posY, const unsigned int width,const unsigned int height);
    void addComponent(Component component);
    void removeComponent(Component component);

private:
    std::vector <Component> components;
};


#endif //PROJECT_PANEL_H
