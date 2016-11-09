//
// Created by Kraghan on 17/10/2016.
//

#include <Control/KeyEvent.hpp>
#include <Control/MouseButtonEvent.hpp>
#include <Control/MouseHoverEvent.hpp>
#include "Control/EventConverter.hpp"


EventConverter::EventConverter()
{
    // None
}

void EventConverter::processEvent(const sf::Event event,const ControlMap*
controlMap)
{
    Actions action;
    // The player use a controller
    if(GameContext::Instance()->isContextController())
    {
        // A controller button is pressed
        if (event.type == sf::Event::JoystickButtonPressed)
        {
            action = controlMap->getAction((int) event.joystickButton
                    .button);
            EventProcessed::event =  KeyEvent(action,true);
        }
            // A controller button is released
        else if (event.type == sf::Event::JoystickButtonReleased)
        {
            action = controlMap->getAction((int) event.joystickButton.button);
            EventProcessed::event =  KeyEvent(action,false);
        }
    }
        // The player use a keyboard and a mouse
    else
    {
        // A key is pressed
        if (event.type == sf::Event::KeyPressed)
        {
            action = controlMap->getAction((int) event.key.code);
            EventProcessed::event =   KeyEvent(action,true);
        }
            // A key is released
        else if (event.type == sf::Event::KeyReleased)
        {
            action = controlMap->getAction((int) event.key.code);
            EventProcessed::event =   KeyEvent(action,false);
        }
            // A mouse button is pressed
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                action = controlMap->getAction(-1);
                EventProcessed::event =   MouseButtonEvent(action,true,sf::Vector2i(event
                                                                       .mouseButton.x,
                                                              event.mouseButton.y));
            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {
                action = controlMap->getAction(-2);
                EventProcessed::event =   MouseButtonEvent(action,true,
                                                           sf::Vector2i(event.mouseButton.x,
                                                              event.mouseButton.y));
            }
            else if(event.mouseButton.button == sf::Mouse::Middle)
            {
                action = controlMap->getAction(-3);
                EventProcessed::event = MouseButtonEvent(action,true,
                                                         sf::Vector2i(event.mouseButton.x,
                                                              event.mouseButton.y));
            }

        }
            // A mouse button is released
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                action = controlMap->getAction(-1);
                EventProcessed::event =   MouseButtonEvent(action,false,
                                                           sf::Vector2i(event.mouseButton.x,
                                                              event.mouseButton.y));
            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {
                action = controlMap->getAction(-2);
                EventProcessed::event =   MouseButtonEvent(action,false,sf::Vector2i(event
                                                                     .mouseButton.x,
                                                              event.mouseButton.y));
            }
            else if(event.mouseButton.button == sf::Mouse::Middle)
            {
                action = controlMap->getAction(-3);
                EventProcessed::event =   MouseButtonEvent(action,false,sf::Vector2i(event
                                                                     .mouseButton.x,
                                                              event.mouseButton.y));

            }
        }
            // Used for hover detection for buttons
        else if (event.type == sf::Event::MouseMoved) {
            action = controlMap->getAction(-1);
            EventProcessed::event = MouseHoverEvent(action,true,sf::Vector2i(event
                                                                     .mouseButton.x,
                                                          event.mouseButton.y));
        }
    }
}
