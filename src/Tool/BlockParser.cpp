//
// Created by Kraghan on 11/10/2016.
//

#include "Tool/BlockParser.hpp"

BlockParser::BlockParser()
{

}

BlockParser::~BlockParser()
{

}

void BlockParser::readMeta(std::istringstream* iss,int* type, unsigned int* width, unsigned int * height,
                           unsigned int* size, std::string* name)
{
    std::string varName,trash;
    *iss >> varName;
    if(varName == "{")
        return;
    if(varName == "}"){
        *type = 0;
        return;
    }
    *iss >> trash;
    if(varName == "NAME")
        *iss >> *name;
    if(varName == "SIZE")
        *iss >> *size;
    if(varName == "WIDTH")
        *iss >> *width;
    if(varName == "HEIGHT")
        *iss >> *height;
}

void BlockParser::readLayer(std::ifstream *infile, std::istringstream* iss,int* type, unsigned int* width,
                            unsigned int* height, std::vector<LayerData> &v)
{
    std::string varName,line;
    *iss >> varName;
    if(varName == "{") {
        std::vector<char> vector;
        char tampon;
        for(unsigned int i = 0; i < *height; ++i)
        {
            std::getline(*infile, line);
            std::istringstream iss2(line);

            for(unsigned int j = 0; j < *width; ++j)
            {
                iss2 >> tampon;
                vector.push_back(tampon);
            }
        }

        LayerData l = LayerData(vector);
        v.push_back(l);
    }
    if(varName == "}"){
        *type = 3;
        return;
    }
}

void BlockParser::readCollider(std::ifstream *infile, std::istringstream* iss, int* type,
                               const unsigned int size,std::vector<Collider> &v)
{
    std::string varName,line;
    *iss >> varName;
    if(varName == "{") {
        unsigned int x, y, width, height;
        char firstChar = varName[0];
        while(firstChar != '}')
        {
            std::getline(*infile, line);
            std::istringstream iss2(line);
            iss2 >> firstChar;
            if(firstChar == '[')
            {
                iss2 >> x >> y >> width >> height;
                Collider c = Collider(x,y,width,height,size);
                v.push_back(c);
            }
        }
        return;
    }
    if(varName == "}"){
        *type = 5;
        return;
    }

}

BlockComponent BlockParser::readFile(std::string file)
{
    std::ifstream infile(file);

    if(infile.good())
    {
        std::vector<LayerData> v_layerData;
        std::vector<Collider> v_collider;
        std::string name = "No name";

        unsigned int size = 0, width = 0, height = 0;

        std::string line;

        /*
         * 0 = Dans aucun block
         * 1 = Dans la META
         * 2 = Dans DATA
         * 3 = Dans un LAYER
         * 4 = Dans LAYER > DATA
         * 5 = Dans PHYSIC
         * 6 = Dans COLLIDER
         */
        int type = 0;

        while (std::getline(infile, line)) {
            if(line[0] == '#' || line[0] == '{')
                continue;

            std::istringstream iss(line);
            if(type == 0) {
                std::string typeBlock;
                iss >> typeBlock;
                if(typeBlock == "META")
                {
                    type = 1;
                }
                if(typeBlock == "DATA")
                {
                    type = 2;
                }
                if(typeBlock == "PHYSIC")
                {
                    type = 5;
                }
            }
            else if(type == 1)
            {
                this->readMeta(&iss,&type,&width,&height,&size,&name);
            }
            else if(type == 2)
            {
                std::string varName;
                iss >> varName;
                if(varName == "{")
                    continue;
                if(varName == "}"){
                    type = 0;
                    continue;
                }

                if(varName == "LAYER")
                    type = 3;
            }
            else if(type == 3)
            {
                std::string varName;
                iss >> varName;
                if(varName == "{")
                    continue;
                if(varName == "}"){
                    type = 2;
                    continue;
                }

                if(varName == "DATA")
                    type = 4;

            }
            else if(type == 4)
            {
                this->readLayer(&infile,&iss,&type,&width,&height,v_layerData);
            }
            else if(type == 5)
            {
                std::string varName;
                iss >> varName;
                if(varName == "{")
                    continue;
                if(varName == "}"){
                    type = 0;
                    continue;
                }

                if(varName == "COLLIDER")
                {
                    type = 6;
                }
            }
            else if(type == 6)
            {
                readCollider(&infile,&iss,&type,size,v_collider);
            }
        }

        BlockComponent compo = BlockComponent(name, size, width, height, v_layerData,v_collider);

        return compo;
    }
    else {
        // TODO : TO MAKE IT BETTER
        std::vector<LayerData> v;
        std::vector<Collider> vv;
        BlockComponent attr = BlockComponent("Error not found",0,0,0,v,vv);
        std::cout << "File not found : " << file <<std::endl;
        return attr;
    }
}