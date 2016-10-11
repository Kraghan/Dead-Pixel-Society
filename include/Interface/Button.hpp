//
// Created by Kraghan on 04/10/2016.
//

#ifndef PROJECT_BUTTON_HPP
#define PROJECT_BUTTON_HPP

#include "Interface/Component.hpp"

class Button : public Component{

public:
    explicit Button(const int posX,const int posY, const unsigned int width,const unsigned int height, std::string strId);

};


#endif //PROJECT_BUTTON_HPP
