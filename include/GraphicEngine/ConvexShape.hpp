#ifndef __CONVEXSHAPE_HPP
#define __CONVEXSHAPE_HPP

#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>

#include "GraphicEngine/Shape.hpp"

class ConvexShape : public Shape
{
public:

    /*!
     * \brief   Constructor
     * \param   pointCount
     */
    explicit ConvexShape(std::size_t pointCount = 0);


    void setPointCount(std::size_t count);
    virtual std::size_t getPointCount() const;
    void setPoint(std::size_t index, const sf::Vector2f& point);
    virtual sf::Vector2f getPoint(std::size_t index) const;

private:

    std::vector<sf::Vector2f> m_points;
};

#endif // __CONVEXSHAPE_HPP