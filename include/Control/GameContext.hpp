//
// Created by madjo on 13/10/2016.
//

#ifndef PROJECT_GAMECONTEXT_HPP
#define PROJECT_GAMECONTEXT_HPP


#include <GameEngine/Singleton.hpp>

class GameContext : public Singleton <GameContext> {

private:
    bool m_menu,m_controller;
    GameContext();

public:
    void setMenuContext();
    void setGameContext();
    void setControllerContext();
    void setKeyboardContext();
    bool isContextMenu();
    bool isContextController();
};


#endif //PROJECT_GAMECONTEXT_HPP
