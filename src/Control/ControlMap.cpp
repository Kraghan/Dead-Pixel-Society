//
// Created by Kraghan on 13/10/2016.
//

#include "Control/ControlMap.hpp"
#include "Tool/ControlParser.hpp"

ControlMap::ControlMap()
{
    ControlParser parser = ControlParser();
    ControlMap map = parser.readSetting();

    m_map_game_controller = map.m_map_game_controller;
    m_map_game = map.m_map_game;
    m_map_menu_controller = map.m_map_menu_controller;
    m_map_menu = map.m_map_menu;
}

ControlMap::ControlMap(int up,int down,int left,int right,int attack,int jump,int activate,int validate,int exit,
                       int pause,int c_attack,int c_jump,int c_activate,int c_validate,int c_exit,int c_pause)
{
    // Keyboard + in game
    m_map_game[up] = Actions::UP;
    m_map_game[down] = Actions::DOWN;
    m_map_game[left] = Actions::LEFT;
    m_map_game[right] = Actions::RIGHT;
    m_map_game[attack] = Actions::ATTACK;
    m_map_game[jump] = Actions::JUMP;
    m_map_game[activate] = Actions::ACTIVATE;
    m_map_game[pause] = Actions::PAUSE;

    // Keyboard + in menu
    m_map_menu[up] = Actions::PREVIOUS;
    m_map_menu[left] = Actions::PREVIOUS;
    m_map_menu[down] = Actions::NEXT;
    m_map_menu[right] = Actions::NEXT;
    m_map_menu[-1] = Actions::VALIDATE;
    m_map_menu[validate] = Actions::VALIDATE;
    m_map_menu[exit] = Actions::EXIT;
    m_map_menu[pause] = Actions::PAUSE;

    // Controller + in game
    // TODO : JOYSTICK CONTROLS
    /*m_map_game_controller[up] = Actions::UP;
    m_map_game_controller[down] = Actions::DOWN;
    m_map_game_controller[left] = Actions::LEFT;
    m_map_game_controller[right] = Actions::RIGHT;*/
    m_map_game_controller[c_attack] = Actions::ATTACK;
    m_map_game_controller[c_jump] = Actions::JUMP;
    m_map_game_controller[c_activate] = Actions::ACTIVATE;
    m_map_game_controller[c_pause] = Actions::PAUSE;

    // Controller + in menu
    /*m_map_menu[up] = Actions::PREVIOUS;
    m_map_menu[left] = Actions::PREVIOUS;
    m_map_menu[down] = Actions::NEXT;
    m_map_menu[right] = Actions::NEXT;*/
    m_map_menu_controller[c_validate] = Actions::VALIDATE;
    m_map_menu_controller[c_exit] = Actions::EXIT;
    m_map_menu_controller[c_pause] = Actions::PAUSE;

}

Actions ControlMap::getAction(int keyPressed) const
{
    GameContext* context = GameContext::instance;
    if(context->isContextMenu())
    {
        if(context->isContextController())
        {
            if(m_map_menu_controller.find(keyPressed) != m_map_menu_controller.end())
            {
                return m_map_menu_controller.find(keyPressed)->second;
            }
            else
            {
                return Actions::NONE;
            }
        }
        else
        {
            if(m_map_menu.find(keyPressed) != m_map_menu.end())
            {
                return m_map_menu.find(keyPressed)->second;
            }
            else
            {
                return Actions::NONE;
            }
        }
    }
    else
    {
        if(context->isContextController())
        {
            if(m_map_game_controller.find(keyPressed) != m_map_game_controller.end())
            {
                return m_map_game_controller.find(keyPressed)->second;
            }
            else
            {
                return Actions::NONE;
            }
        }
        else
        {
            if(m_map_game.find(keyPressed) != m_map_game.end())
            {
                return m_map_game.find(keyPressed)->second;
            }
            else
            {
                return Actions::NONE;
            }
        }
    }
}

void ControlMap::debug()
{
    using namespace std;
    cout << "Mapping for keyboard in game : " << endl;
    for (map<int,Actions>::iterator it=m_map_game.begin(); it!=m_map_game.end(); ++it)
    {
        cout << "\tKey : " << it->first << " = Actions : ";
        switch (it->second)
        {
            case Actions::UP :
                cout<< "UP"<<endl;
                break;
            case Actions::DOWN :
                cout<< "DOWN"<<endl;
                break;
            case Actions::LEFT :
                cout<< "LEFT"<<endl;
                break;
            case Actions::RIGHT :
                cout<< "RIGHT"<<endl;
                break;
            case Actions::ATTACK :
                cout<< "ATTACK"<<endl;
                break;
            case Actions::ACTIVATE :
                cout<< "ACTIVATE"<<endl;
                break;
            case Actions::JUMP :
                cout<< "JUMP"<<endl;
                break;
            case Actions::PAUSE :
                cout<< "PAUSE"<<endl;
                break;
            default :
                cout<< "NONE"<<endl;
                break;
        }
    }

    cout << "Mapping for keyboard in menu : " << endl;
    for (map<int,Actions>::iterator it=m_map_menu.begin(); it!=m_map_menu.end(); ++it)
    {
        cout << "\tKey : " << it->first << " = Actions : ";
        switch (it->second)
        {
            case Actions::UP :
                cout<< "UP"<<endl;
                break;
            case Actions::DOWN :
                cout<< "DOWN"<<endl;
                break;
            case Actions::LEFT :
                cout<< "LEFT"<<endl;
                break;
            case Actions::RIGHT :
                cout<< "RIGHT"<<endl;
                break;
            case Actions::VALIDATE :
                cout<< "VALIDATE"<<endl;
                break;
            case Actions::EXIT :
                cout<< "EXIT"<<endl;
                break;
            case Actions::PAUSE :
                cout<< "PAUSE"<<endl;
                break;
            case Actions::PREVIOUS :
                cout<< "PREVIOUS"<<endl;
                break;
            case Actions::NEXT :
                cout<< "NEXT"<<endl;
                break;
            default :
                cout<< "NONE"<<endl;
                break;
        }
    }

    cout << "Mapping for controller in game : " << endl;
    for (map<int,Actions>::iterator it=m_map_game_controller.begin(); it!=m_map_game_controller.end(); ++it)
    {
        cout << "\tKey : " << it->first << " = Actions : ";
        switch (it->second)
        {
            case Actions::UP :
                cout<< "UP"<<endl;
                break;
            case Actions::DOWN :
                cout<< "DOWN"<<endl;
                break;
            case Actions::LEFT :
                cout<< "LEFT"<<endl;
                break;
            case Actions::RIGHT :
                cout<< "RIGHT"<<endl;
                break;
            case Actions::ATTACK :
                cout<< "ATTACK"<<endl;
                break;
            case Actions::ACTIVATE :
                cout<< "ACTIVATE"<<endl;
                break;
            case Actions::JUMP :
                cout<< "JUMP"<<endl;
                break;
            case Actions::PAUSE :
                cout<< "PAUSE"<<endl;
                break;
            default :
                cout<< "NONE"<<endl;
                break;
        }
    }

    cout << "Mapping for controller in menu : " << endl;
    for (map<int,Actions>::iterator it=m_map_menu_controller.begin(); it!=m_map_menu_controller.end(); ++it)
    {
        cout << "\tKey : " << it->first << " = Actions : ";
        switch (it->second)
        {
            case Actions::UP :
                cout<< "UP"<<endl;
                break;
            case Actions::DOWN :
                cout<< "DOWN"<<endl;
                break;
            case Actions::LEFT :
                cout<< "LEFT"<<endl;
                break;
            case Actions::RIGHT :
                cout<< "RIGHT"<<endl;
                break;
            case Actions::VALIDATE :
                cout<< "VALIDATE"<<endl;
                break;
            case Actions::EXIT :
                cout<< "EXIT"<<endl;
                break;
            case Actions::PAUSE :
                cout<< "PAUSE"<<endl;
                break;
            case Actions::PREVIOUS :
                cout<< "PREVIOUS"<<endl;
                break;
            case Actions::NEXT :
                cout<< "NEXT"<<endl;
                break;
            default :
                cout<< "NONE"<<endl;
                break;
        }
    }

}