//
// Created by kraghan on 27/09/2016.
//

#ifndef PROJECT_COMPONENT_H
#define PROJECT_COMPONENT_H

#include "GraphicEngine/Sprite.hpp"
#include "SFML/Graphics.hpp"

class Component {
public:
    // Constructor
    /*!
     *
     * @param posX
     * @param posY
     * @param width
     * @param height
     * @param strId
     * @return
     */
    explicit Component(const int posX,const int posY, const int width,const int height, std::string strId);

    // Modify component
    /*!
     *
     * @param posX
     * @param posY
     */
    void move(const int posX, const int posY);

    /*!
     *
     * @param position
     */
    void move(const sf::Vector2i position);

    /*!
     *
     * @param width
     * @param height
     */
    void resize(const int width,const int height);

    /*!
     *
     * @param size
     */
    void resize(const sf::Vector2i size);

    // Getter

    /*!
     *
     * @return
     */
    const int getX();

    /*!
     *
     * @return
     */
    const int getY();

    /*!
     *
     * @return
     */
    const sf::Vector2i getPosition();

    /*!
     *
     * @return
     */
    const int getWidth();

    /*!
     *
     * @return
     */
    const int getHeight();

    /*!
     *
     * @return
     */
    const sf::Vector2i getDimension();

    /*!
     *
     * @param s
     */
    void setBackground(Sprite* s);

    /*!
     *
     * @return
     */
    Sprite* getBackground();

    /*!
     *
     * @param l
     */
    void setLayer(int l);

    /*!
     *
     * @return
     */
    const int getLayer();

    /*!
     *
     * @return
     */
    const size_t getID();
protected:
private:
Sprite * background;
sf::Vector2i point,dimension;
int layer;
size_t ID;
};


#endif //PROJECT_COMPONENT_H
