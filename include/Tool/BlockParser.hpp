//
// Created by madjo on 11/10/2016.
//

#ifndef PROJECT_BLOCKPARSER_HPP
#define PROJECT_BLOCKPARSER_HPP


#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Dungeon/BlockAttributes.hpp"
#include "PhysicEngine/PhysicAttributes.hpp"
#include "Tool/BlockComponent.hpp"

class BlockParser
{
private:
    void readMeta(std::istringstream* iss,int* type, unsigned int* width, unsigned int * height,
                  unsigned int* size, std::string* name);
    void readLayer(std::ifstream *infile, std::istringstream* iss,int* type, unsigned int* width,
                   unsigned int* height, std::vector<LayerData> &v);
    void readCollider(std::ifstream *infile, std::istringstream* iss, int* type,
                      const unsigned int size,std::vector<Collider> &v);
public:
    BlockParser();
    ~BlockParser();

    BlockComponent readFile(std::string file);
};

#endif //PROJECT_BLOCKPARSER_HPP
