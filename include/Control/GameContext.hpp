//
// Created by madjo on 13/10/2016.
//

#ifndef PROJECT_GAMECONTEXT_HPP
#define PROJECT_GAMECONTEXT_HPP


class GameContext {

private:
    bool m_menu,m_controller;
    static GameContext* m_context;
    GameContext();

public:
    static GameContext* getContext()
    {
        if(m_context == nullptr)
        {
            m_context = new GameContext();
        }
        return m_context;
    }
    void setMenuContext();
    void setGameContext();
    void setControllerContext();
    void setKeyboardContext();
    bool isContextMenu();
    bool isContextController();
};


#endif //PROJECT_GAMECONTEXT_HPP
