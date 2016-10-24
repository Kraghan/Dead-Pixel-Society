#include <iostream>
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
    m_layerPrimitive = sf::Triangles;
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

// Very bad ... think about drawable ...
void Layer::append(Sprite const * sprite, double offset)
{
    // std::cout << offset << std::endl;
    // If none, this the first append
    if(m_type == LAYER_TYPE::NONE)
    {
        m_type = LAYER_TYPE::SPRITE;

        if(!m_wireframe)
        {
            // On the first time, we have
            // set the render states
            m_state->texture = sprite->getTexture();
            m_layerPrimitive = sf::Triangles;
        }
        else
        {
            m_layerPrimitive = sf::Lines;
        }
    }
    else if(m_type == LAYER_TYPE::TEXT)
    {
        // Layer type and drawable type mismatched
        // Skipping
        m_skipped++;
        return;
    }
    else if(m_type == LAYER_TYPE::SHAPE)
    {
        m_skipped++;
        return;
    }

    uint32_t inc = 6;
    if(m_wireframe) inc = 10;

    // Checking layer overflow
    if(m_size + inc >= m_capacity)
    {
        // There is an overflow
        // Skipping
        m_skipped++;
        return;
    }

    // We can add the vertices
    // Getting the target vertices
    const sf::Vertex * _vertices = sprite->getVertices();

    // Buffering rigidbody
    bool smooth = sprite->getSmoothMotion();
    RigidBody * _rigid = sprite->getRigidBody();

    if(m_wireframe)
    {
        // First line
        memcpy((void *)&m_vertices[m_size + 0], &_vertices[0], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 1], &_vertices[1], sizeof(sf::Vertex));

        // Second line
        memcpy((void *)&m_vertices[m_size + 2], &_vertices[1], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 3], &_vertices[2], sizeof(sf::Vertex));

        // Third line
        memcpy((void *)&m_vertices[m_size + 4], &_vertices[2], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 5], &_vertices[0], sizeof(sf::Vertex));

        // Fourth line
        memcpy((void *)&m_vertices[m_size + 6], &_vertices[1], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 7], &_vertices[3], sizeof(sf::Vertex));

        // Fifth line
        memcpy((void *)&m_vertices[m_size + 8], &_vertices[3], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 9], &_vertices[2], sizeof(sf::Vertex));

        // Buffering transformation
        const sf::Transform * _transform = &sprite->getTransform();

        // Iterating vertices
        for(unsigned i = 0; i < inc; ++i)
        {
            // Applying transformation to the vertices
            m_vertices[m_size + i].position  = *_transform * m_vertices[m_size + i].position;

            m_vertices[m_size + i].texCoords = sf::Vector2f(0.0f, 0.0f);
            m_vertices[m_size + i].color     = sprite->getWireColor();

            if(smooth)
            {
                if(_rigid != nullptr)
                {
                    m_vertices[m_size + i].position.x += _rigid->getVelocity().x * offset;
                    m_vertices[m_size + i].position.y += _rigid->getVelocity().y * offset;

                    /*
                    std::cout << "offset : " << offset << std::endl;

                    std::cout << _rigid->getVelocity().x << std::endl;
                    std::cout << _rigid->getVelocity().y << std::endl;

                    std::cout << _rigid->getVelocity().x * offset << std::endl;
                    std::cout << _rigid->getVelocity().y * offset << std::endl;

                    std::cout << std::endl;
                    */
                }
            }
        }

        m_size += inc;
    }
    else
    {
        // Make two triangles from a triangle strip (Clockwise)
        // Copying efficiently vertices
        // So we can copy the first three triangles
        memcpy((void *)&m_vertices[m_size + 0], _vertices, 3 * sizeof(sf::Vertex));

        // And then we have to copy the triangles left
        // in the array to break the triangle strip
        memcpy((void *)&m_vertices[m_size + 3], (void *)&_vertices[1], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 4], (void *)&_vertices[3], sizeof(sf::Vertex));
        memcpy((void *)&m_vertices[m_size + 5], (void *)&_vertices[2], sizeof(sf::Vertex));

        // Buffering transformation
        const sf::Transform * _transform = &sprite->getTransform();

        // Iterating vertices
        for(unsigned i = 0; i < inc; ++i)
        {
            // Applying transformation to the vertices
            m_vertices[m_size + i].position = *_transform * m_vertices[m_size + i].position;

            if(smooth)
            {
                if(_rigid != nullptr)
                {
                    m_vertices[m_size + i].position.x += _rigid->getVelocity().x * offset;
                    m_vertices[m_size + i].position.y += _rigid->getVelocity().y * offset;
                }
            }
        }

        // Then incrementing the size of the layer
        // and we're done
        m_size += inc;
    }
}

// Very bad ... think about drawable ...
void Layer::append(ConvexShape const * shape, double offset)
{
    // If none, this the first append
    if(m_type == LAYER_TYPE::NONE)
    {
        m_type = LAYER_TYPE::SHAPE;

        if(!m_wireframe)
        {
            // On the first time, we have
            // set the render states
            m_state->texture = shape->getTexture();
            m_layerPrimitive = sf::Triangles;
        }
        else
        {
            m_layerPrimitive = sf::Lines;
        }
    }
    else if(m_type == LAYER_TYPE::TEXT)
    {
        // Layer type and drawable type mismatched
        // Skipping
        m_skipped++;
        return;
    }
    else if(m_type == LAYER_TYPE::SPRITE)
    {
        m_skipped++;
        return;
    }

    // Setting inc value
    uint32_t inc = (uint32_t)shape->getPointCount() * 3;
    if(m_wireframe) inc *= 2;

    // Checking layer overflow
    if(m_size + inc >= m_capacity)
    {
        // There is an overflow
        // Skipping
        m_skipped++;
        return;
    }

    // We can add the vertices
    // Getting the target vertices
    const sf::Vertex * _vertices = shape->getVertices();

    // Buffering middle points
    const sf::Vertex * _middle = &_vertices[0];

    // Redefining pointer
    _vertices = &_vertices[1];

    // Buffering transformation
    const sf::Transform * _transform = &shape->getTransform();

    // Buffering points count
    uint32_t pCount = (uint32_t)shape->getPointCount();

    if(m_wireframe)
    {
        // Buffering first point
        const sf::Vertex * _buffer = _vertices;

        // Making lines
        for(uint32_t i = 0; i < pCount; ++i)
        {
            makeTriangleLine(m_size + i * 6, _buffer, _middle, &_vertices[i + 1]);
            _buffer = &_vertices[i + 1];
        }

        // Buffering smooth motion state
        bool smooth = shape->getSmoothMotion();
        RigidBody * _rigid = shape->getRigidBody();

        // Direct transform
        for(uint32_t i = 0; i < inc; ++i)
        {
            m_vertices[m_size + i].position = *_transform * m_vertices[m_size + i].position;
            m_vertices[m_size + i].texCoords = sf::Vector2f(0, 0);
            m_vertices[m_size + i].color = shape->getWireColor();

            // Smooth motion
            if(smooth)
            {
                if(_rigid != nullptr)
                {
                    m_vertices[m_size + i].position.x += _rigid->getVelocity().x * offset;
                    m_vertices[m_size + i].position.y += _rigid->getVelocity().y * offset;
                }
            }
        }
    }
    else
    {
        // Generating triangles from triangle fan
        for(uint32_t i = 0; i < (uint32_t)shape->getPointCount(); ++i)
        {
            memcpy((void *)&m_vertices[m_size + i + 0], (void *)&_vertices[i + 1], sizeof(sf::Vertex));
            memcpy((void *)&m_vertices[m_size + i + 1], (void *)&_vertices[i + 2], sizeof(sf::Vertex));

            // Inserting middle points
            memcpy((void *)&m_vertices[m_size + i + 2], (void *)_middle, sizeof(sf::Vertex));
        }
    }

    m_size += inc;
}

void Layer::makeTriangleLine(uint32_t index,
    const sf::Vertex * p1,
    const sf::Vertex * p2,
    const sf::Vertex * p3)
{
    // Line 1
    memcpy((void *)&m_vertices[index + 0], (void *)p1, sizeof(sf::Vertex));
    memcpy((void *)&m_vertices[index + 1], (void *)p3, sizeof(sf::Vertex));

    // Line 2
    memcpy((void *)&m_vertices[index + 2], (void *)p3, sizeof(sf::Vertex));
    memcpy((void *)&m_vertices[index + 3], (void *)p2, sizeof(sf::Vertex));

    // Line 3
    memcpy((void *)&m_vertices[index + 4], (void *)p2, sizeof(sf::Vertex));
    memcpy((void *)&m_vertices[index + 5], (void *)p1, sizeof(sf::Vertex));
}