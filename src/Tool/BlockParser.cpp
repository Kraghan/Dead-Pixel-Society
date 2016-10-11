//
// Created by madjo on 11/10/2016.
//

#include "Tool/BlockParser.hpp"

BlockParser::BlockParser()
{

}

BlockParser::~BlockParser()
{

}

BlockAttributes BlockParser::readFile(std::string file)
{
    std::ifstream infile(file);

    if(infile.good())
    {
        std::vector<LayerData> v;
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
                std::string varName,trash;
                iss >> varName;
                if(varName == "{")
                    continue;
                if(varName == "}"){
                    type = 0;
                    continue;
                }
                iss >> trash;
                if(varName == "NAME")
                    iss >> name;
                if(varName == "SIZE")
                    iss >> size;
                if(varName == "WIDTH")
                    iss >> width;
                if(varName == "HEIGHT")
                    iss >> height;
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
                std::string varName;
                iss >> varName;
                if(varName == "{") {
                    std::vector<char> vector;
                    char tampon;
                    for(unsigned int i = 0; i < height; ++i)
                    {
                        std::getline(infile, line);
                        std::istringstream iss2(line);

                        for(unsigned int j = 0; j < width; ++j)
                        {
                            iss2 >> tampon;
                            vector.push_back(tampon);
                        }
                    }

                    LayerData l = LayerData(vector);
                    v.push_back(l);
                }
                if(varName == "}"){
                    type = 3;
                    continue;
                }

            }



        }
        //std::cout<<"Name : "<<name<< " Width : " << width << " Height : " << height<< " Size : " << size <<std::endl;

        BlockAttributes attr = BlockAttributes(name, size, width, height, v);
        return attr;
    }
    else {
        std::vector<LayerData> v;
        BlockAttributes attr = BlockAttributes(" ", 0, 0, 0, v);
        std::cout << "File not found" << std::endl;
        return attr;
    }
}