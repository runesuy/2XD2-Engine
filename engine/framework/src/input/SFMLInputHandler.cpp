//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/input/SFMLInputHandler.h"

#include <SFML/Window/Event.hpp>

#include "2XD2/framework/input/SFMLToInputMap.h"
#include "2XD2/core/exceptions/NotInitializedException.h"

namespace e2XD::framework::internal
{
    void SFMLInputHandler::pollEvents()
    {
        windowResized = {false, 0, 0};
        windowClosed = false;

        if (!window) throw core::NotInitializedException("SFMLInputHandler", "void SFMLInputHandler::pollEvents()");

        const auto posM = sf::Mouse::getPosition();
        mousePosition = core::Vec2f(posM.x, posM.y);

        sf::Event event{};
        while (window->pollEvent(event))
        {
            handleEvent(event);
        }
    }

    void SFMLInputHandler::handleEvent(const sf::Event& event)
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handleKeyPress(event.key.code);
            break;
        case sf::Event::KeyReleased:
            handleKeyRelease(event.key.code);
            break;
        case sf::Event::MouseButtonPressed:
            handleMouseButtonPress(event.mouseButton.button);
            break;
        case sf::Event::MouseButtonReleased:
            handleMouseButtonRelease(event.mouseButton.button);
            break;
        case sf::Event::Resized:
            windowResized = {true, event.size.width, event.size.height};
            break;
        case sf::Event::Closed:
            windowClosed = true;
            break;
        default: break;
        }
    }

    std::tuple<bool, float, float> SFMLInputHandler::isWindowResized() const
    {
        return windowResized;
    }

    bool SFMLInputHandler::isKeyReleased(const Key keyCode) const
    {
        if (this_frame_keyboardState.contains(keyCode)) return !this_frame_keyboardState.at(keyCode);
        return false;
    }

    core::Vec2f SFMLInputHandler::getMousePosition() const
    {
        return mousePosition;
    }

    bool SFMLInputHandler::isKeyPressed(const Key keyCode) const
    {
        if (this_frame_keyboardState.contains(keyCode)) return this_frame_keyboardState.at(keyCode);
        return false;
    }

    bool SFMLInputHandler::isMouseButtonPressed(const MouseButton buttonCode) const
    {
        if (this_frame_mouseButtonState.contains(buttonCode)) return this_frame_mouseButtonState.at(buttonCode);
        return false;
    }

    bool SFMLInputHandler::isMouseButtonReleased(const MouseButton buttonCode) const
    {
        if (this_frame_mouseButtonState.contains(buttonCode)) return !this_frame_mouseButtonState.at(buttonCode);
        return false;
    }

    void SFMLInputHandler::initialize(sf::RenderWindow* window)
    {
        this->window = window;
    }

    bool SFMLInputHandler::isWindowClosed() const
    {
        return windowClosed;
    }

    void SFMLInputHandler::handleKeyPress(sf::Keyboard::Key sfmlKeyCode)
    {
        if (input::keyboardMap.contains(sfmlKeyCode))
        {
            this_frame_keyboardState[input::keyboardMap.at(sfmlKeyCode)] = true;
        }
    }

    void SFMLInputHandler::handleKeyRelease(sf::Keyboard::Key sfmlKeyCode)
    {
        if (input::keyboardMap.contains(sfmlKeyCode))
        {
            this_frame_keyboardState[input::keyboardMap.at(sfmlKeyCode)] = false;
        }
    }

    void SFMLInputHandler::handleMouseButtonPress(sf::Mouse::Button sfmlButtonCode)
    {
        if (input::mouseButtonMap.contains(sfmlButtonCode))
        {
            this_frame_mouseButtonState[input::mouseButtonMap.at(sfmlButtonCode)] = true;
        }
    }

    void SFMLInputHandler::handleMouseButtonRelease(sf::Mouse::Button sfmlButtonCode)
    {
        if (input::mouseButtonMap.contains(sfmlButtonCode))
        {
            this_frame_mouseButtonState[input::mouseButtonMap.at(sfmlButtonCode)] = false;
        }
    }

    bool SFMLInputHandler::isKeyJustPressed(const Key keyCode) const
    {
        if (this_frame_keyboardState.contains(keyCode) && this_frame_keyboardState.at(keyCode) && (!
            last_frame_keyboardState.contains(keyCode) || !last_frame_keyboardState.at(keyCode)))
        {
            return true;
        }
        return false;
    }

    bool SFMLInputHandler::isKeyJustReleased(const Key keyCode) const
    {
        if (last_frame_keyboardState.contains(keyCode) && last_frame_keyboardState.at(keyCode) && (!
            this_frame_keyboardState.contains(keyCode) || !this_frame_keyboardState.at(keyCode)))
        {
            return true;
        }
        return false;
    }

    bool SFMLInputHandler::isMouseButtonJustPressed(const MouseButton buttonCode) const
    {
        if (this_frame_mouseButtonState.contains(buttonCode) && this_frame_mouseButtonState.at(buttonCode) && (!
            last_frame_mouseButtonState.contains(buttonCode) || !last_frame_mouseButtonState.at(buttonCode)))
        {
            return true;
        }
        return false;
    }

    bool SFMLInputHandler::isMouseButtonJustReleased(const MouseButton buttonCode) const
    {
        if (last_frame_mouseButtonState.contains(buttonCode) && last_frame_mouseButtonState.at(buttonCode) && (!
            this_frame_mouseButtonState.contains(buttonCode) || !this_frame_mouseButtonState.at(buttonCode)))
        {
            return true;
        }
        return false;
    }

    void SFMLInputHandler::newFrame()
    {
        last_frame_mouseButtonState = this_frame_mouseButtonState;
        last_frame_keyboardState = this_frame_keyboardState;
    }
} // core
