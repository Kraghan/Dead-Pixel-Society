//
// Created by kraghan on 27/09/2016.
//

#ifndef PROJECT_COMPONENT_H
#define PROJECT_COMPONENT_H


class Component {
public:
    explicit Component(const int posX,const int posY, const unsigned int width,const unsigned int height);
    void move(const int posX, const int posY);
    void resize(const unsigned int width,const unsigned int height);

    const int getX();
    const int getY();
    const unsigned int getWidth();
    const unsigned int getHeight();
protected:
private:
    int x,y;
    unsigned int width,height;
};


#endif //PROJECT_COMPONENT_H
