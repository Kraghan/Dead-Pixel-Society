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
     * @param posX int : Position en x du coin haut gaauche du component
     * @param posY int : Position en y du coin haut gaauche du component
     * @param width int : Largeur du component
     * @param height int : Hauteur du component
     * @param strId std::string : Chaine representant l'ID du component
     * @return Component
     */
    explicit Component(const int posX,const int posY, const int width,const int height, std::string strId);

    // Modify component
    /*!
     *
     * @param posX int : Nouvelle position en x du coin haut gauche du component
     * @param posY int : Nouvelle position en y du coin haut gauche du component
     */
    void move(const int posX, const int posY);

    /*!
     *
     * @param position sf::Vector2i : Nouvelle position en x et y du coin haut gauche du component
     */
    void move(const sf::Vector2i position);

    /*!
     *
     * @param width int : Nouvelle largeur du component
     * @param height int : Nouvelle hauteur du component
     */
    void resize(const int width,const int height);

    /*!
     *
     * @param size sf::Vector2i : Nouvelles dimensions du component
     */
    void resize(const sf::Vector2i size);

    // Getter

    /*!
     *
     * @return int : Position x du coin haut gauche du component
     */
    const int getX();

    /*!
     *
     * @return int : Position y du coin haut gauche du component
     */
    const int getY();

    /*!
     *
     * @return sf::Vector2i : Position du coin haut gauche du component
     */
    const sf::Vector2i getPosition();

    /*!
     *
     * @return int : Largeur du component
     */
    const int getWidth();

    /*!
     *
     * @return int : Hauteur du component
     */
    const int getHeight();

    /*!
     *
     * @return sf::Vector2i : Dimensions du component
     */
    const sf::Vector2i getDimension();

    /*!
     *
     * @param s Sprite* : Affecte un fond au component
     */
    void setBackground(Sprite* s);

    /*!
     *
     * @return Sprite* : Retourne le sprite de fond
     */
    Sprite* getBackground();

    /*!
     *
     * @param l int : Affecte le rang d'affichage du component. Plus le rang est faible, plus il sera affiche en fond.
     */
    void setLayer(int l);

    /*!
     *
     * @return int : Retourne le rang d'affichage
     */
    const int getLayer();

    /*!
     *
     * @return size_t : Retourne l'ID hasher
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
