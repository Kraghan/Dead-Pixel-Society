//
// Created by Kraghan on 13/10/2016.
//

#ifndef PROJECT_CONTROLMAP_HPP
#define PROJECT_CONTROLMAP_HPP

#include "Control/EnumActions.hpp"
#include "Control/GameContext.hpp"

#include <iostream>
#include <map>

class ControlMap {
private:
    std::map <int,Actions> m_map_game, m_map_menu, m_map_game_controller, m_map_menu_controller;
public:
    ControlMap();
    ControlMap(int up,int down,int left,int right,int attack,int jump,int activate,int validate,int exit,int pause,
               int c_attack,int c_jump,int c_activate,int c_validate,int c_exit,int c_pause);

    Actions getAction(int keyPressed);

    void debug();
};


#endif //PROJECT_CONTROLMAP_HPP
