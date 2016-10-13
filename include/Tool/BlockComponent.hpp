#ifndef __BLOCK_COMPONENT_HPP
#define __BLOCK_COMPONENT_HPP

#include "PhysicEngine/PhysicAttributes.hpp"
#include "Dungeon/BlockAttributes.hpp"

class BlockComponent
{
public:

    /*!
     * \brief   Constructor
     * \param   name The name of the block
     * \param   size The size of a sprite
     * \param   width The width of a block (in sprite)
     * \param   height The height of a block (in sprite)
     * \param   v_layerData The raw data of the layer
     * \param   v_collider The colliders information
     */
    BlockComponent(std::string const& name,
                   unsigned int size,
                   unsigned int width,
                   unsigned int height,
                   std::vector<LayerData> const& v_layerData,
                   std::vector<Collider>  const& v_collider);

private:

    BlockAttributes m_blockAttributes;
    PhysicAttributes m_physicAttributes;

    /*!
     * \brief   Display the content of the block component
     */
    void debug();
};

#endif //__BLOCK_COMPONENT_HPP
