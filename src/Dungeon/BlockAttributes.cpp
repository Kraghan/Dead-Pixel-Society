//
// Created by Kraghan on 11/10/2016.
//
#include "Dungeon/BlockAttributes.hpp"

BlockAttributes::BlockAttributes()
{

}


BlockAttributes::BlockAttributes(std::string name, unsigned int spriteSize, unsigned int width, unsigned int height,
                                 std::vector<LayerData> const&spriteDatas)
{
    m_name = name;
    m_spriteSize = spriteSize;
    m_width = width;
    m_height = height;
    m_spritesData = spriteDatas;
}

const std::string &BlockAttributes::getName() const {
    return m_name;
}

unsigned int BlockAttributes::getSpriteSize() const {
    return m_spriteSize;
}

unsigned int BlockAttributes::getWidth() const {
    return m_width;
}

unsigned int BlockAttributes::getHeight() const {
    return m_height;
}

const std::vector<LayerData> &BlockAttributes::getSpritesData() const {
    return m_spritesData;
}

void BlockAttributes::debug()
{
    using namespace std;
    cout<< "Name : " << m_name <<endl;
    cout<< "Sprite size : " << m_spriteSize <<endl;
    cout<< "Width : " << m_width <<endl;
    cout<< "Height : " << m_height <<endl;

    for(unsigned int k = 0; k < m_spritesData.size(); ++k)
    {
        LayerData l = m_spritesData[k];
        vector<char> v = l.getLayerData();
        cout<< "Layer : " << k <<endl;
        for (unsigned int i = 0; i < m_height; ++i) {
            for (unsigned int j = 0; j < m_width; ++j) {
                cout << v[i*m_width + j] << " ";
            }
            cout<<endl;
        }
    }
}

