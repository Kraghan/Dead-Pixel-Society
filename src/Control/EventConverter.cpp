//
// Created by Kraghan on 17/10/2016.
//

#include "Control/EventConverter.hpp"


EventConverter::EventConverter()
{
    // None
}

void EventConverter::processEvent(const sf::Event event,const ControlMap*
controlMap)
{
    bool isPressed = false;
    Actions action = Actions::NONE;
    GameContext* context = GameContext::Instance();

    sf::Vector2i position = sf::Vector2i(-1,-1);
    EventType type = EventType::VOID;
    // The player use a controller
    if(context->isContextController())
    {
        // A controller button is pressed
        if (event.type == sf::Event::JoystickButtonPressed)
        {
            isPressed = true;
            action = controlMap->getAction((int) event.joystickButton.button);
        }
            // A controller button is released
        else if (event.type == sf::Event::JoystickButtonReleased)
        {
            action = controlMap->getAction((int) event.joystickButton.button);
        }
    }
        // The player use a keyboard and a mouse
    else
    {
        // A key is pressed
        if (event.type == sf::Event::KeyPressed)
        {
            isPressed = true;
            action = controlMap->getAction((int) event.key.code);
        }
            // A key is released
        else if (event.type == sf::Event::KeyReleased)
        {
            action = controlMap->getAction((int) event.key.code);
        }
            // A mouse button is pressed
        else if (event.type == sf::Event::MouseButtonPressed)
        {

            if(event.mouseButton.button == sf::Mouse::Left)
            {
                position = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
                action = controlMap->getAction(-1);
                if(action == Actions::VALIDATE)
                {
                    type = EventType::MOUSE_LEFT_CLICK;
                }
            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {
                position = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
                action = controlMap->getAction(-2);
                if(action == Actions::VALIDATE)
                {
                    type = EventType::MOUSE_LEFT_CLICK;
                }
            }
            else if(event.mouseButton.button == sf::Mouse::Middle)
            {
                position = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
                action = controlMap->getAction(-3);
                if(action == Actions::VALIDATE)
                {
                    type = EventType::MOUSE_LEFT_CLICK;
                }
            }

        }
            // A mouse button is released
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                action = controlMap->getAction(-1);

            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {
                action = controlMap->getAction(-2);

            }
            else if(event.mouseButton.button == sf::Mouse::Middle)
            {
                action = controlMap->getAction(-3);

            }
        }
            // Used for hover detection for buttons
        else if (event.type == sf::Event::MouseMoved) {
            type = EventType::MOUSE_HOVER;
            position = sf::Vector2i(event.mouseMove.x,event.mouseMove.y);
        }
    }
    EventProcessed::action = action;
    EventProcessed::event = Event(position,type,isPressed);
}
