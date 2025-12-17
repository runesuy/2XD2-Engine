//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/SFMLInputHandler.h"

#include <SFML/Window/Event.hpp>

#include "2XD2/framework/SFMLToInputMap.h"
#include "2XD2/framework/exceptions/NotInitializedException.h"

namespace e2XD::framework
{
    SFMLInputHandler* SFMLInputHandler::getInstance()
    {
        if (!_instance) _instance = new SFMLInputHandler();
        return _instance;
    }

    SFMLInputHandler::~SFMLInputHandler()
    {
        delete _instance;
    }

    void SFMLInputHandler::pollEvents()
    {
        mousePressedMap.clear();
        mouseReleasedMap.clear();
        keyboardPressedMap.clear();
        keyboardReleasedMap.clear();
        windowResized = {false,0,0};
        windowClosed = false;

        if (!window) throw NotInitializedException("SFMLInputHandler", "void SFMLInputHandler::pollEvents()");

        const auto posM = sf::Mouse::getPosition();
        mousePosition = core::Vec2(posM.x, posM.y);

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
            addKeyFromSFMLKeyCode(event.key.code, keyboardPressedMap);
            break;
        case sf::Event::KeyReleased:
            addKeyFromSFMLKeyCode(event.key.code, keyboardReleasedMap);
            break;
        case sf::Event::MouseButtonPressed:
            addMouseButtonFromSFMLButtonCode(event.mouseButton.button, mousePressedMap);
            break;
        case sf::Event::MouseButtonReleased:
            addMouseButtonFromSFMLButtonCode(event.mouseButton.button, mouseReleasedMap);
            break;
        case sf::Event::Resized:
            windowResized = {true, event.size.width,event.size.height};
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
        if (keyboardReleasedMap.contains(keyCode)) return keyboardReleasedMap.at(keyCode);
        return false;
    }

    core::Vec2 SFMLInputHandler::getMousePosition() const
    {
        return mousePosition;
    }

    bool SFMLInputHandler::isKeyPressed(const Key keyCode) const
    {
        if (keyboardPressedMap.contains(keyCode)) return keyboardPressedMap.at(keyCode);
        return false;
    }

    bool SFMLInputHandler::isMouseButtonPressed(MouseButton buttonCode) const
    {
        if (mousePressedMap.contains(buttonCode)) return mousePressedMap.at(buttonCode);
        return false;
    }

    bool SFMLInputHandler::isMouseButtonReleased(MouseButton buttonCode) const
    {
        if (mouseReleasedMap.contains(buttonCode)) return mouseReleasedMap.at(buttonCode);
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

    void SFMLInputHandler::addKeyFromSFMLKeyCode(const sf::Keyboard::Key sfmlKeyCode, keyboardMapType& keyboardMap)
    {
        if (input::keyboardMap.contains(sfmlKeyCode))
        {
            keyboardMap[input::keyboardMap.at(sfmlKeyCode)] = true;
        }
    }

    void SFMLInputHandler::addMouseButtonFromSFMLButtonCode(const sf::Mouse::Button sfmlButtonCode, mouseButtonMapType& mouseButtonMap)
    {
        if (input::mouseButtonMap.contains(sfmlButtonCode))
        {
            mouseButtonMap[input::mouseButtonMap.at(sfmlButtonCode)] = true;
        }
    }



} // core
