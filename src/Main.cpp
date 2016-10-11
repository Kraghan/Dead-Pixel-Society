#include <cstdlib>
#include "GameEngine/GameEngine.hpp"
#include "Interface/Panel.hpp"
#include "Interface/Component.hpp"

int main(void)
{
    GameEngine gameEngine;

    gameEngine.init();
    gameEngine.start();

    /*
     * Debug interface
    Panel* panel = new Panel(10,10,500,500,"Panel de test");
    panel->debugVector();
    Component* c1 = new Component(20,20,100,100,"C1");

    Component* c2 = new Component(360,360,100,100,"C2");

    Component* c3 = new Component(20,360,100,100,"C3");

    Component* c4 = new Component(360,20,100,100,"C4");

    panel->addComponent(c1);
    panel->debugVector();
    panel->addComponent(c2);
    panel->debugVector();
    panel->addComponent(c3);
    panel->debugVector();
    panel->addComponent(c4);
    panel->debugVector();

    panel->removeComponent(c3);
    delete c3;
    panel->debugVector();
    panel->removeComponent(c2);
    delete c2;
    panel->debugVector();
    panel->removeComponent(c1);
    delete c1;
    panel->debugVector();
    panel->removeComponent(c4);
    delete c4;
    panel->debugVector();
    delete panel;*/
    return EXIT_SUCCESS;
}