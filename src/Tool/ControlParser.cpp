//
// Created by Kraghan on 13/10/2016.
//

#include "Tool/ControlParser.hpp"


ControlParser::ControlParser()
{
    // None
}

void ControlParser::readMovement(std::ifstream* infile, int* up, int* down, int* left, int* right)
{
    std::string line;
    while(getline(*infile, line) && line != "")
    {
        if (line[0] == '#')
            continue;

        std::istringstream iss(line);

        std::string varName;
        char trash;
        int value;
        iss >> varName >> trash >> value;

        if(varName == "UP")
        {
            *up = value;
        }
        else if(varName == "DOWN")
        {
            *down = value;
        }
        else if(varName == "LEFT")
        {
            *left = value;
        }
        else if(varName == "RIGHT")
        {
            *right = value;
        }
    }

}
void ControlParser::readActions(std::ifstream* infile, int* attack, int* jump, int* activate)
{
    std::string line;
    while(std::getline(*infile, line) && line != "")
    {
        if (line[0] == '#')
            continue;

        std::istringstream iss(line);

        std::string varName;
        char trash;
        int value;
        iss >> varName >> trash >> value;

        if(varName == "ATTACK")
        {
            *attack = value;
        }
        else if(varName == "JUMP")
        {
            *jump = value;
        }
        else if(varName == "ACTIVATE")
        {
            *activate = value;
        }
    }

}

void ControlParser::readMenu(std::ifstream* infile, int* validate, int* exit, int* pause)
{
    std::string line;
    while(std::getline(*infile, line) && line != "")
    {
        if (line[0] == '#')
            continue;

        std::istringstream iss(line);

        std::string varName;
        char trash;
        int value;
        iss >> varName >> trash >> value;

        if(varName == "VALIDATE")
        {
            *validate = value;
        }
        else if(varName == "EXIT")
        {
            *exit = value;
        }
        else if(varName == "PAUSE")
        {
            *pause = value;
        }
    }

}

void ControlParser::readActionsController(std::ifstream* infile, int* c_attack, int* c_jump, int* c_activate)
{
    std::string line;
    while(std::getline(*infile, line) && line != "")
    {
        if (line[0] == '#')
            continue;

        std::istringstream iss(line);

        std::string varName;
        char trash;
        int value;
        iss >> varName >> trash >> value;

        if(varName == "ATTACK")
        {
            *c_attack = value;
        }
        else if(varName == "JUMP")
        {
            *c_jump = value;
        }
        else if(varName == "ACTIVATE")
        {
            *c_activate = value;
        }
    }

}

void ControlParser::readMenuController(std::ifstream* infile, int* c_validate, int* c_exit, int* c_pause)
{
    std::string line;
    while(std::getline(*infile, line) && line != "")
    {
        if (line[0] == '#')
            continue;

        std::istringstream iss(line);

        std::string varName;
        char trash;
        int value;
        iss >> varName >> trash >> value;

        if(varName == "VALIDATE")
        {
            *c_validate = value;
        }
        else if(varName == "EXIT")
        {
            *c_exit = value;
        }
        else if(varName == "PAUSE")
        {
            *c_pause = value;
        }
    }

}

ControlMap ControlParser::readSetting()
{
    std::string path = "..\\settings\\control.ini", line;

    std::ifstream infile(path);

    // Default key
    int up = 25, down = 18, left = 16, right = 3, attack = -1, jump = 57, activate = 4, validate = 4, exit = 36,
            pause = 36, c_attack = 2, c_jump = 0, c_activate = 3, c_validate = 0, c_exit = 1, c_pause = 7;

    if(infile.good())
    {
        while (std::getline(infile, line)) {
            if (line[0] == '#')
                continue;

            if(line == "[MOVEMENT]")
            {
                this->readMovement(&infile,&up,&down,&left,&right);
            }
            else if(line == "[ACTION]")
            {
                this->readActions(&infile,&attack,&jump,&activate);
            }
            else if(line == "[MENU]")
            {
                this->readMenu(&infile,&validate,&exit,&pause);
            }
            else if(line == "[ACTION-CONTROLLER]")
            {
                this->readActionsController(&infile,&c_attack,&c_jump,&c_activate);
            }
            else if(line == "[MENU-CONTROLLER]")
            {
                this->readMenuController(&infile,&c_validate,&c_exit,&c_pause);
            }
        }


    }
    else
    {
        std::cerr<< "File not found" <<std::endl;
    }

    return ControlMap(up,down,left,right,attack,jump,activate,validate,exit,pause,c_attack,c_jump,c_activate,
                      c_validate,c_exit,c_pause);
}

