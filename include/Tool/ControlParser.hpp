//
// Created by Kraghan on 13/10/2016.
//

#ifndef PROJECT_CONTROLPARSER_HPP
#define PROJECT_CONTROLPARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Control/ControlMap.hpp"

class ControlParser {
public:
    ControlParser();
    ControlMap readSetting();
private:
    void readMovement(std::ifstream* infile, int* up, int* down, int* left, int* right);
    void readActions(std::ifstream* infile, int* attack, int* jump, int* activate);
    void readMenu(std::ifstream* infile, int* validate, int* exit, int* pause);
    void readActionsController(std::ifstream* infile, int* c_attack, int* c_jump, int* c_activate);
    void readMenuController(std::ifstream* infile, int* c_validate, int* c_exit, int* c_pause);

};


#endif //PROJECT_CONTROLPARSER_HPP
