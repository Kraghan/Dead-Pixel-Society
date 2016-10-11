//
// Created by Karghan on 27/09/2016.
//

#ifndef PROJECT_PANEL_H
#define PROJECT_PANEL_H

#include <vector>
#include <iostream>

#include "Component.hpp"

class Panel : public Component{
public:
    /*!
     *
     * @param posX int : Position en x du coin haut gauche du panel
     * @param posY int : Position en y du coin haut gauche du panel
     * @param width int : Largeur du panel
     * @param height int : Hauteur du panel
     * @param strId std::string : Chaine representant l'ID du panel
     * @return Panel
     */
    explicit Panel(const int posX,const int posY, const unsigned int width,const unsigned int height, std::string strId);

    /*!
     * Ajoute le component au panel et modifie ses coordonnées
     * @param component Component a ajouter
     */
    void addComponent(Component* component);

    /*!
     * Enleve le component au panel
     * @param component Component a enlever
     */
    void removeComponent(Component* component);

    void addListener(Listener* listener);

    void setBackground(Sprite* s);

    // Juste pour debug et test
    void debugVector();

private:
    std::vector <Component*> m_components;
};

#endif //PROJECT_PANEL_H
