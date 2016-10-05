#include "GraphicEngine/RenderBase.hpp"

RenderBase::RenderBase()
{
    m_layer = -1;
    m_ready = false;
    m_visible = true;
    m_available = true;
}

void RenderBase::update()
{
    // A drawable is ready to be displayed if :
    // His layer is different of -1
    // He is visible
    // He is not available in the engine (so in use in the game)
    m_ready = !(m_layer == -1 || !m_visible || m_available);
}

void RenderBase::free()
{
    // The game doesn't own this
    // sprite anymore
    m_available = true;
}