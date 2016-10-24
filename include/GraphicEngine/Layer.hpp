/*!
 * \brief    Contains the header of the
 *           class Layer
 *
 * \file     Layer.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     04/10/2016
 */

#ifndef __LAYER_HPP
#define __LAYER_HPP

#include <cstring>
#include <SFML/Graphics.hpp>
#include "GraphicEngine/Sprite.hpp"
#include "GraphicEngine/ConvexShape.hpp"

class Layer
{
public:

    /*!
     * \brief   A enum to store the type of the layer
     *          because a layer could not contains
     *          sprites and texts at the same times
     */
    enum LAYER_TYPE
    {
        NONE,
        TEXT,
        SHAPE,
        SPRITE,
    };

    /*!
     * \brief   Default constructor
     */
    explicit Layer();

    /*!
     * \brief   Destructor
     */
    virtual ~Layer();

    /*!
     * \brief   Reset the layer for next frame
     */
    void prepare();

    /*!
     * \brief   Append the vertices of a sprite
     *          to the layer
     * \param   sprite A const pointer on the sprite
     *          to append to the layer
     */
    void append(Sprite const * sprite);

    /*!
     * \brief   Append the vertices of a sprite
     *          to the layer
     * \param   sprite A const pointer on the sprite
     *          to append to the layer
     */
    void append(ConvexShape const * shape);

    /*!
     * \brief   Initialize the layer
     */
    void init(unsigned layerSize);

    /*!
     * \brief   Return the current size of the layer
     * \return  The size of the layer
     */
    inline unsigned getSize() const
    {
        return m_size;
    }

    /*!
     * \brief   Return the capacity of the layer
     * \return  The capacity of the layer
     */
    inline unsigned getCapacity() const
    {
        return m_capacity;
    }

    /*!
     * \brief   Return a pointer on the layer vertices
     * \return  The layer vertices
     */
    inline const sf::Vertex * getVertices() const
    {
        return m_vertices;
    }

    /*!
     * \brief   Return a pointer on the render state
     * \return  The layer render state
     */
    inline sf::RenderStates const& getState() const
    {
        return *m_state;
    }

    /*!
    * \brief   Return the number of sprite skipped
    * \return  The number of sprite skipped
    */
    inline uint32_t getSkipped() const
    {
        return m_skipped;
    }

    /*!
     * \brief   Set the wireframe mode to state
     * \param   state The state of the wireframe mode
     */
    inline void setWireframe(bool state)
    {
        m_wireframe = state;
    }

    /*!
     * \brief   Return the layer primitive
     */
    inline sf::PrimitiveType getPrimitive() const
    {
        return m_layerPrimitive;
    }

private:

    unsigned m_size;
    unsigned m_capacity;
    sf::Vertex * m_vertices;
    sf::RenderStates * m_state;

    LAYER_TYPE m_type;

    /*!
     * \brief   Debug variable
     */
    uint32_t m_skipped;

    /*!
     * \brief   When true, display the game in wireframe !
     */
    bool m_wireframe;

    /*!
     * \brief   Define the layer primitive
     */
    sf::PrimitiveType m_layerPrimitive;

    /*!
     * \brief   Make a triangle with lines
     */
    void makeTriangleLine(uint32_t index,
                          const sf::Vertex * p1,
                          const sf::Vertex * p2,
                          const sf::Vertex * p3);
};

#endif // __LAYER_HPP
