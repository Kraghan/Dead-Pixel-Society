//
// Created by madjo on 11/10/2016.
//

#ifndef PROJECT_BLOCKPARSER_HPP
#define PROJECT_BLOCKPARSER_HPP

#include <iostream>
#include <string>
#include <Dungeon/BlockAttributes.hpp>

class BlockParser
{
public:
    BlockParser();
    ~BlockParser();

    BlockAttributes readFile(std::string file);
};

#endif //PROJECT_BLOCKPARSER_HPP
