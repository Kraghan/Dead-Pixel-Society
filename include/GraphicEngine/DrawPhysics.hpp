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

private:

    Sprite * m_panel;
    ResourceManager * m_resourceManager;
    std::vector < sf::Text > m_information;

    uint32_t m_colliderCount;
    uint32_t m_rigidBodyCount;
    uint32_t m_bindCount;

    /*!
     * \brief   Set the string in each text
     */
    void setTextContent();
};


#endif //PROJECT_DRAWPHYSICS_HPP
