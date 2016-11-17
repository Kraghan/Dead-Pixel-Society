#include "GraphicEngine/ConvexShape.hpp"


ConvexShape::ConvexShape(std::size_t pointCount)
{
    setPointCount(pointCount);
}

void ConvexShape::setPointCount(std::size_t count)
{
    m_points.resize(count);
    update();
}

std::size_t ConvexShape::getPointCount() const
{
    return m_points.size();
}

void ConvexShape::setPoint(std::size_t index, const sf::Vector2f& point)
{
    m_points[index] = point;
    update();
}

sf::Vector2f ConvexShape::getPoint(std::size_t index) const
{
    return m_points[index];
}

void ConvexShape::release(ConvexShape *& shape)
{
    // There is no points to try to
    // release a null pointer
    if(shape == nullptr) return;

    // The game doesn't own this
    // sprite anymore
    shape->setAvailable(true);

    // Setting the pointer to nullptr
    shape = nullptr;
}