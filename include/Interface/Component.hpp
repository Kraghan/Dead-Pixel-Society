//
// Created by kraghan on 27/09/2016.
//

#ifndef PROJECT_COMPONENT_H
#define PROJECT_COMPONENT_H

#include "GraphicEngine/Sprite.hpp"
#include "SFML/Graphics.hpp"
#include "Interface/Listener.hpp"

#include <iostream>

class Component {
public:
    // Constructor
    /*!
     * Constructeur
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
     * Deplace le component au coordonnee (posX, posY)
     * @param posX int : Nouvelle position en x du coin haut gauche du component
     * @param posY int : Nouvelle position en y du coin haut gauche du component
     */
    void move(const int posX, const int posY);

    /*!
     * Deplace le component au coordonnee de position
     * @param position sf::Vector2i : Nouvelle position en x et y du coin haut gauche du component
     */
    void move(const sf::Vector2i position);

    /*!
     * Redimensionne le component au dimension (width, height)
     * @param width int : Nouvelle largeur du component
     * @param height int : Nouvelle hauteur du component
     */
    void resize(const int width,const int height);

    /*!
     * Redimension le component au dimension size
     * @param size sf::Vector2i : Nouvelles dimensions du component
     */
    void resize(const sf::Vector2i size);

    // Getter

    /*!
     * Retourne la postion en x du coin haut gauche du component
     * @return int : Position x du coin haut gauche du component
     */
    const int getX();

    /*!
     * Retourne la postion en y du coin haut gauche du component
     * @return int : Position y du coin haut gauche du component
     */
    const int getY();

    /*!
     * Retourne la postion du coin haut gauche du component
     * @return sf::Vector2i : Position du coin haut gauche du component
     */
    const sf::Vector2i getPosition();

    /*!
     * Retourne la largueur du component
     * @return int : Largeur du component
     */
    const int getWidth();

    /*!
     * Retourne la hauteur du component
     * @return int : Hauteur du component
     */
    const int getHeight();

    /*!
     * Retourne les dimensions du component
     * @return sf::Vector2i : Dimensions du component
     */
    const sf::Vector2i getDimension();

    /*!
     * Affecte un fond au component
     * @param s Sprite* : Affecte un fond au component
     */
    virtual void setBackground(Sprite* s) = 0;

    /*!
     * Retourne le sprite de fond
     * @return Sprite* : Retourne le sprite de fond
     */
    Sprite* getBackground();

    /*!
     * Affecte le rang d'affichage du component. Plus le rang est faible, plus il sera affiche en fond.
     * @param l int : Rang d'affichage
     */
    void setLayer(int l);

    /*!
     * Retourne le rang d'affichage
     * @return int : Retourne le rang d'affichage
     */
    const int getLayer();

    /*!
     * Retourne l'ID hashee
     * @return size_t : Retourne l'ID hasher
     */
    const size_t getID();

    virtual void addListener(Listener* listener) = 0;
private:
    Sprite * m_pbackground;
    sf::Vector2i m_point,m_dimension;
    int m_layer;
    size_t m_ID;
    Listener* m_plistener;
};


#endif //PROJECT_COMPONENT_H
