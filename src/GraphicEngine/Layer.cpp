#include "GraphicEngine/Layer.hpp"

/*explicit */ Layer::Layer()
: m_size(0)
, m_capacity(0)
, m_vertices(nullptr)
, m_state(nullptr)
, m_type(LAYER_TYPE::NONE)
, m_skipped(0)
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

    // Resetting debug
    m_skipped = 0;
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
        m_skipped++;
        return;
    }

    // Checking layer overflow
    if(m_size + 6 >= m_capacity)
    {
        // There is an overflow
        // Skipping
        m_skipped++;
        return;
    }

    // We can add the vertices
    // Getting the target vertices
    const sf::Vertex * _vertices = sprite->getVertices();

    // Make two triangles from a triangle strip (Clockwise)
    // Copying efficiently vertices
    // So we can copy the first three triangles
    memcpy((void *)&m_vertices[m_size], _vertices, 3 * sizeof(sf::Vertex));

    // And then we have to copy the triangles left
    // in the array to break the triangle strip
    memcpy((void *)&m_vertices[m_size + 3], (void *)&_vertices[1], sizeof(sf::Vertex));
    memcpy((void *)&m_vertices[m_size + 4], (void *)&_vertices[3], sizeof(sf::Vertex));
    memcpy((void *)&m_vertices[m_size + 5], (void *)&_vertices[2], sizeof(sf::Vertex));

    // Buffering transformation
    const sf::Transform * _transform = &sprite->getTransform();

    // Iterating vertices
    for(unsigned i = 0; i < 6; ++i)
    {
        // Applying transformation to the vertices
        m_vertices[m_size + i].position = *_transform * m_vertices[m_size + i].position;
    }

    // Then incrementing the size of the layer
    // and we're done
    m_size += 6;
}