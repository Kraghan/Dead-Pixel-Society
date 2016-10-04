#include "GraphicEngine/Layer.hpp"

/*explicit */ Layer::Layer()
: m_size(0)
, m_capacity(0)
, m_vertices(nullptr)
, m_state(nullptr)
, m_type(LAYER_TYPE::NONE)
{
    // None
}

/* virtual */ Layer::~Layer()
{
    // Freeing memory
    delete m_state;
    delete [] m_vertices;
}

void Layer::init(unsigned layerSize)
{
    // Creating layer
    m_capacity = layerSize;
    m_state = new sf::RenderStates();
    m_vertices = new sf::Vertex[m_capacity];
}

void Layer::prepare()
{
    // Resetting the size
    m_size = 0;

    // Resetting the state
    m_state->texture = nullptr;
    m_state->shader  = nullptr;

    // Resetting the type
    m_type = LAYER_TYPE::NONE;
}

void Layer::append(Sprite const * sprite)
{
    // If none, this the first append
    if(m_type == LAYER_TYPE::NONE)
    {
        m_type = LAYER_TYPE::SPRITE;

        // On the first time, we have
        // set the render states
        m_state->texture = sprite->getTexture();
    }
    else if(m_type == LAYER_TYPE::TEXT)
    {
        // Layer type and drawable type mismatched
        // Skipping
        return;
    }

    // Checking layer overflow
    if(m_size + 4 >= m_capacity)
    {
        // There is an overflow
        // Skipping
        return;
    }

    // We can add the vertices
    // Getting the target vertices
    const sf::Vertex * _vertices = sprite->getVertices();

    // Copying efficiently vertices
    memcpy((void *)&m_vertices[m_size], _vertices, 4 * sizeof(sf::Vertex));

    for(unsigned i = 0; i < 4; ++i)
    {
        // Applying transformation to the vertices
        m_vertices[m_size + i].position = sprite->getTransform() *
                                          m_vertices[m_size + i].position;
    }

    // Then incrementing the size of the layer
    // and we're done
    m_size += 4;
}