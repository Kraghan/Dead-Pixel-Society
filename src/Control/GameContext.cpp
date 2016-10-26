//
// Created by Kraghan on 13/10/2016.
//

#include "Control/GameContext.hpp"

GameContext::GameContext()
{
    m_menu = false;
    m_controller = false;
}

void GameContext::setMenuContext()
{
    m_menu = true;
}

void GameContext::setGameContext()
{
    m_menu = false;
}

void GameContext::setControllerContext()
{
    m_controller = true;
}

void GameContext::setKeyboardContext()
{
    m_controller = true;
}

bool GameContext::isContextMenu()
{
    return m_menu;
}

bool GameContext::isContextController()
{
    return m_controller;
}