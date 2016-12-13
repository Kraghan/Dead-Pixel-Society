//
// Created by Kraghan on 16/11/2016.
//

#include <Tool/Patch.hpp>
#include "GraphicEngine/DrawPhysics.hpp"
#include "PhysicEngine/PhysicEngine.hpp"
bool DrawPhysics::m_active = false;

DrawPhysics::DrawPhysics()
: m_panel(nullptr)
, m_resourceManager(nullptr)
, m_physicEngine(nullptr)
{
    // None
}

DrawPhysics::~DrawPhysics()
{
    // None
}

void DrawPhysics::init(ResourceManager * resourceManager)
{
    m_drawn = false;
    m_resourceManager = resourceManager;
    m_physicEngine = m_resourceManager->getPhysicEngine();


    m_colliderCount = resourceManager->getTotalCollider();
    m_rigidBodyCount = resourceManager->getTotalRigidBody();
    m_bindCount = resourceManager->getTotalBinding();

    std::string testString = PANEL_KEY;

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

        _text.setFillColor(sf::Color::White);
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
    if(m_active) {
        // Preparing strings
        setTextContent();

        for (uint32_t index = 0; index < m_information.size(); ++index) {
            // Draw all the information text
            window->draw(m_information[index]);
        }

        std::vector<Collider> colliders = m_physicEngine->getAllColliders();
        std::vector<RigidBody> rigidBodies = m_physicEngine->getAllRigidBodies();

        if (!m_drawn) {
            m_panel = m_resourceManager->getSprite();
            m_panel->setLayer(14);
            sf::Texture * testTexture = m_resourceManager->getTexture(PANEL_KEY);
            m_panel->setTexture(*testTexture);
            m_panel->setPosition(PANEL_POS_X_PHYSIC,
                                 PANEL_POS_Y);

            for (unsigned int i = 0; i < colliders.size(); ++i)
            {
                if (colliders[i].isFree() || !colliders[i].isReady()
                    || colliders[i].isEnabled())
                    continue;

                ConvexShape *c = m_resourceManager->getConvexShape();
                if(c != nullptr)
                {
                    c->setLayer(9);
                    if(colliders[i].getTriggerAction() == nullptr)
                    {
                        c->setWireColor(sf::Color::Cyan);
                        c->setFillColor(sf::Color::Cyan);
                    }
                    else
                    {
                        c->setWireColor(sf::Color::Green);
                        c->setFillColor(sf::Color::Green);
                    }
                    c->setPointCount(4);
                    c->setPoint(0, colliders[i].getPosition());

                    c->setPoint(1, sf::Vector2f(colliders[i].getPosition().x
                                                + colliders[i].getDimension().x,
                                                colliders[i].getPosition().y));

                    c->setPoint(2, colliders[i].getPosition() + colliders[i]
                            .getDimension());

                    c->setPoint(3, sf::Vector2f(colliders[i].getPosition().x,
                                                colliders[i].getPosition().y
                                                + colliders[i].getDimension().y));

                    m_shapes.push_back(c);
                }
            }
            for (unsigned int i = 0; i < rigidBodies.size(); ++i)
            {
                if (rigidBodies[i].isFree() || !rigidBodies[i].isReady()
                                               || rigidBodies[i].isEnabled())
                    continue;

                ConvexShape *c = m_resourceManager->getConvexShape();
                if(c != nullptr)
                {
                    c->setLayer(9);
                    c->setPointCount(4);
                    c->setPoint(0, rigidBodies[i].getPosition());

                    c->setPoint(1, sf::Vector2f(rigidBodies[i].getPosition().x
                                                +
                                                rigidBodies[i].getDimension().x +
                                                10.0f,
                                                rigidBodies[i].getPosition().y));

                    c->setPoint(2, sf::Vector2f(rigidBodies[i].getPosition().x +
                                                rigidBodies[i].getDimension().x +
                                                10.0f,
                                                rigidBodies[i].getPosition().y +
                                                rigidBodies[i].getDimension().y +
                                                10.0f));

                    c->setPoint(3, sf::Vector2f(rigidBodies[i].getPosition().x,
                                                rigidBodies[i].getPosition().y
                                                +
                                                rigidBodies[i].getDimension().y +
                                                10.0f));

                    c->setWireColor(sf::Color::Red);
                    c->setFillColor(sf::Color::Red);

                    m_shapes.push_back(c);
                }
            }

            m_drawn = true;
        }
        else
        {
            unsigned int j = 0;
            for (unsigned int i = 0; i < colliders.size(); ++i) {
                if (colliders[i].isFree() || !colliders[i].isReady()
                        || colliders[i].isEnabled())
                    continue;

                ConvexShape* c = m_shapes[j];
                if(j < m_shapes.size())
                {
                    c->setPoint(0, colliders[i].getPosition());

                    c->setPoint(1, sf::Vector2f(colliders[i].getPosition().x
                                                + colliders[i].getDimension().x,
                                                colliders[i].getPosition().y));

                    c->setPoint(2, colliders[i].getPosition() + colliders[i]
                            .getDimension());

                    c->setPoint(3, sf::Vector2f(colliders[i].getPosition().x,
                                                colliders[i].getPosition().y
                                                +
                                                colliders[i].getDimension().y));
                    ++j;
                }
            }
            for (unsigned int i = 0; i < rigidBodies.size(); ++i)
            {
                if (rigidBodies[i].isFree() || !rigidBodies[i].isReady()
                        || rigidBodies[i].isEnabled())
                    continue;
                ConvexShape* c = m_shapes[j];
                if(m_shapes.size() > j)
                {
                    c->setPoint(0, rigidBodies[i].getPosition());

                    c->setPoint(1, sf::Vector2f(rigidBodies[i].getPosition().x
                                                +
                                                rigidBodies[i].getDimension().x +
                                                10.0f,
                                                rigidBodies[i].getPosition().y));

                    c->setPoint(2, sf::Vector2f(rigidBodies[i].getPosition().x +
                                                rigidBodies[i].getDimension().x +
                                                10.0f,
                                                rigidBodies[i].getPosition().y +
                                                rigidBodies[i].getDimension().y +
                                                10.0f));

                    c->setPoint(3, sf::Vector2f(rigidBodies[i].getPosition().x,
                                                rigidBodies[i].getPosition().y
                                                +
                                                rigidBodies[i].getDimension().y +
                                                10.0f));
                    ++j;
                }
            }
        }
    }
    else
    {
        Sprite::release(m_panel);
        for(unsigned int i = 0; i < m_shapes.size(); ++i)
        {
            ConvexShape::release(m_shapes[i]);
        }
        m_shapes.clear();
        m_drawn = false;
    }
}

void DrawPhysics::toggleDrawPhysics()
{
    DrawPhysics::m_active = !DrawPhysics::m_active;
}


