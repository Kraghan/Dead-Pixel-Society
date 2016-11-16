//
// Created by Kraghan on 16/11/2016.
//

#include <Tool/Patch.hpp>
#include "GraphicEngine/DrawPhysics.hpp"

DrawPhysics::DrawPhysics()
: m_panel(nullptr)
, m_resourceManager(nullptr)
{
    // None
}

DrawPhysics::~DrawPhysics()
{
    // None
}

void DrawPhysics::init(ResourceManager * resourceManager)
{
    m_resourceManager = resourceManager;
    m_panel = m_resourceManager->getSprite();

    m_colliderCount = resourceManager->getTotalCollider();
    m_rigidBodyCount = resourceManager->getTotalRigidBody();
    m_bindCount = resourceManager->getTotalBinding();

    // Setting the layer
    m_panel->setLayer(14);

    std::string testString = PANEL_KEY;
    sf::Texture * testTexture = m_resourceManager->getTexture(PANEL_KEY);

    m_panel->setTexture(*testTexture);

    // Setting position
    m_panel->setPosition(PANEL_POS_X_PHYSIC,
                         PANEL_POS_Y);

    // Creating all texts
    for(uint32_t index = 0; index < INFO_COUNT_PHYSIC; ++index)
    {
        // Creating the text
        m_information.push_back(sf::Text());

        // Buffering the text
        sf::Text & _text = m_information.back();

        // Setting attributes
        _text.setFont(*m_resourceManager->getFont(FONT_KEY));
        _text.setPosition(TEXT_POS_X_PHYSIC, TEXT_POS_Y + (index *
                                                    (CHAR_SIZE + TEXT_OFFSET)));

        _text.setColor(sf::Color::White);
        _text.setCharacterSize(CHAR_SIZE);
    }

    // Setting fps style
    m_information[1].setStyle(sf::Text::Bold);
}

void DrawPhysics::reset()
{

}

void DrawPhysics::setTextContent()
{
    // Updating all text content with the new values
    m_information[0].setString(ENGINE_VERSION);
    m_information[1].setString(std::string("Update : ")             +
                                       fix::to_string(m_update));
    m_information[2].setString(std::string("Collider count : ")           +
                                       fix::to_string(m_colliderCount));
    m_information[3].setString(std::string("Rigid body : ")     +
                                       fix::to_string(m_rigidBodyCount));
    m_information[4].setString(std::string("Bind : ")  + fix::to_string(m_bindCount));

}

void DrawPhysics::draw(sf::RenderWindow * window)
{
    // Preparing strings
    setTextContent();

    for(uint32_t index = 0; index < m_information.size(); ++index)
    {
        // Draw all the information text
        window->draw(m_information[index]);
    }
}


