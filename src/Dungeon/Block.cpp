#include "Dungeon/Block.hpp"

/* explicit */ Block::Block(ResourceManager * resourceManager, std::string const& theme)
: m_theme(theme)
, m_resourceManager(resourceManager)
, m_spriteSize(0)
, m_blockWidth(0)
, m_blockHeight(0)
, m_blockName("")
{
    // None
}

/* virtual */ Block::~Block()
{
    // None
}

void Block::init(
    std::string const& name,
    uint32_t width,
    uint32_t height,
    uint32_t spriteSize,
    std::vector< LayerData > const& layerData)
{
    // Getting meta info
    m_blockName = name;
    m_blockWidth = width;
    m_blockHeight = height;
    m_spriteSize = spriteSize;

    // Iterating the data layers
    for(uint32_t index = 0; index < layerData.size(); ++index)
    {
        // Pushing a back a new raw data vector
        m_rawData.push_back(std::vector < char > ());

        // Getting the current layer
        LayerData * _layer = (LayerData *)&layerData[index];

        // Extracting raw data from the layers
        std::vector <char > const& _data = _layer->getLayerData();
        getRawData(_data);
    }
}

void Block::getRawData(std::vector<char> const& data)
{
    m_rawData.back() = data;

    // Generating the block
    generateBlock();
}

void Block::generateBlock()
{
    // Pushing the sprite map
    m_spriteMap.push_back(std::vector < Sprite * > ());

    // Buffering vectors
    std::vector < char > const& _data = m_rawData.back();
    std::vector < Sprite * > & _sprites = m_spriteMap.back();

    // Reserving space
    _sprites.reserve(m_blockWidth * m_blockHeight);

    // Iterating raw data
    for(uint32_t i = 0; i < m_blockHeight; ++i)
    {
        for(uint32_t j = 0; j < m_blockWidth; ++j)
        {
            // Buffering index
            uint32_t _index =  i * m_blockWidth + j;

            if(_data[_index] == constant::test::VOID_CASE)
            {
                // Checking the case of a void tile
                _sprites[_index] = nullptr;
            }
            else
            {
                // Else we have to find the good texture
                // By calling an helpful method
                setSprite(j, i, _index);
            }
        }
    }
}

void Block::setSprite(uint32_t x, uint32_t y, uint32_t index)
{
    // Buffering vectors
    std::vector < Sprite * > & _sprites = m_spriteMap.back();

    // Getting a sprite
    _sprites[index] = m_resourceManager->getSprite();

    // Setting his layer
    _sprites[index]->setLayer(m_spriteMap.size() - 1);

    // Getting the texture
    _sprites[index]->setTexture(*m_resourceManager->getTexture(m_theme));

    // Setting the position of the sprite
    float _x = x * m_spriteSize;
    float _y = y * m_spriteSize;

    _sprites[index]->setPosition(_x, _y);

    // Setting the texture rect
    setSpriteTextureRect(index);
}

void Block::setSpriteTextureRect(uint32_t index)
{
    // Buffering vector
    std::vector < char > const& _data = m_rawData.back();
    std::vector < Sprite * > const& _sprites = m_spriteMap.back();

    // Buffering sprite
    Sprite * _sprite = _sprites[index];


    // Handling all case
    switch(_data[index])
    {
        case constant::test::WALL_CASE:
        {
            _sprite->setTextureRect(sf::IntRect(
                    constant::test::WALL_TEXTURE_X * m_spriteSize,
                    constant::test::WALL_TEXTURE_Y * m_spriteSize,
                    m_spriteSize, m_spriteSize));
            break;
        }

        default:
        {
            // Warning the user about this
            std::cerr << "Unhandled character ..." << std::endl;
            break;
        }
    }
}

void Block::hide()
{
    setVisible(false);
}

void Block::show()
{
    setVisible(true);
}

void Block::setVisible(bool visible)
{
    // Hide or Show the blocks
    for(uint32_t index = 0; index < m_spriteMap.size(); ++index)
    {
        // Buffering the vector
        std::vector < Sprite * > const& _sprites = m_spriteMap[index];

        for(Sprite * _sprite : _sprites)
        {
            if(_sprite != nullptr)
            {
                _sprite->setVisible(visible);
            }
        }
    }
}