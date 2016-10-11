#include "Dungeon/Block.hpp"

/* explicit */ Block::Block(ResourceManager * resourceManager, std::string const& theme)
: m_theme(theme)
, m_resourceManager(resourceManager)
, m_layerSize(0)
, m_layerCount(0)
, m_spriteSize(0)
, m_blockWidth(0)
, m_blockHeight(0)
, m_blockName("")
, m_rawData(nullptr)
, m_spriteMap(nullptr)
, m_spriteMapSize(0)
{
    // None
}

/* virtual */ Block::~Block()
{
    // Giving all sprites back to the engine
    for(uint32_t index = 0; index < m_spriteMapSize; ++index)
    {
        // Handle the case where sprite is nullptr
        Sprite::release(m_spriteMap[index]);
    }

    // Freeing memory
    delete [] m_spriteMap;
}

void Block::init(BlockAttributes const& attribute)
{
    // Getting meta info
    m_blockName = attribute.getName();
    m_blockWidth = attribute.getWidth();
    m_blockHeight = attribute.getHeight();
    m_spriteSize = attribute.getSpriteSize();

    // Getting the data section
    // Buffering the data layers
    std::vector < LayerData > _layers = attribute.getSpritesData();

    // Extracting the size
    m_layerCount = _layers.size();

    // Getting the sprite size
    m_spriteSize = attribute.getSpriteSize();

    // Getting layer size
    m_layerSize = m_blockWidth * m_blockHeight;

    // Computing the sprite map size
    m_spriteMapSize = m_layerCount * m_layerSize;

    // Allocating memory
    m_spriteMap = new Sprite * [m_spriteMapSize];

    // Getting raw data
    getRawData(_layers);

    // Warning the user for the end of the generation
    std::cerr << "Block generated." << std::endl;
}

void Block::getRawData(std::vector < LayerData > & layers)
{
    // Iterating the vector
    for(uint32_t index = 0; index < m_layerCount; ++index)
    {
        // Buffering the layer
        std::vector < char > _layer = layers[index].getLayerData();

        // Copying data
        memcpy((void *)&m_rawData[index * m_layerSize],
               (void *)&_layer[0], m_layerSize);
    }

    // Generating the block
    generateBlock();
}

void Block::generateBlock()
{
    // Iterating raw data
    for(uint32_t layer = 0; layer < m_layerCount; ++layer)
    {
        for(uint32_t offset = 0; offset < m_layerSize; ++offset)
        {
            // Buffering current index
            uint32_t _index = layer * m_layerSize + offset;

            if(m_rawData[_index] == constant::test::VOID_CASE)
            {
                // Checking the case of a void tile
                m_spriteMap[_index] = nullptr;
            }
            else
            {
                // Else we have to find the good texture
                // By calling an helpful method
                setSprite(layer, offset, _index);
            }
        }
    }
}

void Block::setSprite(uint32_t layer, uint32_t offset, uint32_t index)
{
    // Getting a sprite
    m_spriteMap[index] = m_resourceManager->getSprite();

    // Setting his layer
    m_spriteMap[index]->setLayer(layer);

    // Getting the texture
    m_spriteMap[index]->setTexture(*m_resourceManager->getTexture(m_theme));

    // Setting the position of the sprite
    float _x = (offset % m_blockWidth) * m_spriteSize;
    float _y = (offset / m_blockWidth) * m_spriteSize;

    m_spriteMap[index]->setPosition(_x, _y);

    // Setting the texture rect
    setSpriteTextureRect(index);
}

void Block::setSpriteTextureRect(uint32_t index)
{
    // Buffering the sprite
    Sprite * _sprite = m_spriteMap[index];

    // Handling all case
    switch(m_rawData[index])
    {
        case constant::test::WALL_CASE:
        {
            _sprite->setTextureRect(sf::IntRect(
                    constant::test::WALL_TEXTURE_X * m_spriteSize,
                    constant::test::WALL_TEXTURE_Y * m_spriteSize,
                    m_spriteSize, m_spriteSize));
        }

        default:
        {
            // Warning the user about this
            std::cerr << "Unhandled character ..." << std::endl;
            break;
        }
    }
}