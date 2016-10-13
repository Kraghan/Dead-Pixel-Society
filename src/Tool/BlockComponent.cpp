#include "Tool/BlockComponent.hpp"

BlockComponent::BlockComponent(
  std::string const& name
, unsigned int size
, unsigned int width
, unsigned int height
, std::vector<LayerData> const& v_layerData
, std::vector<Collider> const& v_collider)

: m_blockAttributes(name, size, width, height, v_layerData)
, m_physicAttributes(v_collider)
{
    // None
}

void BlockComponent::debug()
{
    m_blockAttributes.debug();
    m_physicAttributes.debug();
}

BlockAttributes const &BlockComponent::getBlockAttribute()
{
    return m_blockAttributes;
}
