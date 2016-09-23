#include <iostream>
#include <SFML/Window.hpp>
#include "memory/Container.hpp"


int main(void)
{
    std::cout << "Dead Pixel Society" << std::endl;

    sf::Window window(sf::VideoMode(800, 600), "My window");

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}