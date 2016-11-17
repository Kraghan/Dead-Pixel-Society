//
// Created by Kraghan on 16/11/2016.
//

#ifndef PROJECT_DRAWPHYSICS_HPP
#define PROJECT_DRAWPHYSICS_HPP


#include <Memory/ResourceManager.hpp>
#include <cstdint>
#include "GraphicConstant.hpp"

class DrawPhysics
{
public:

    /*!
     * \brief   Constructor
     */
    explicit DrawPhysics();

    /*!
     * \brief   Destructor
     */
    virtual ~DrawPhysics();

    /*!
     * \brief   Initialize the debug panel
     * \param   resourceManager A pointer on the resource manager
     */
    void init(ResourceManager * resourceManager);

    /*!
     * \brief   Reset data for the  next frame
     */
    void reset();

    /*!
     * \brief       Draw the debug panel
     * \deprecated  Use the legacy draw for the moment
     */
    void draw(sf::RenderWindow * window);

    /*!
     * \brief   Debug information
     */
    double m_update;

    static void toggleDrawPhysics();

    static bool m_active;
private:

    bool m_drawn;
    Sprite * m_panel;
    ResourceManager * m_resourceManager;
    PhysicEngine* m_physicEngine;
    std::vector < sf::Text > m_information;
    std::vector < ConvexShape* > m_shapes;

    uint32_t m_colliderCount;
    uint32_t m_rigidBodyCount;
    uint32_t m_bindCount;

    /*!
     * \brief   Set the string in each text
     */
    void setTextContent();
};


#endif //PROJECT_DRAWPHYSICS_HPP
