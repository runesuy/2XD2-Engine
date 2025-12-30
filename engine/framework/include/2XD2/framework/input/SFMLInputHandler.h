//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_INPUTMANAGER_H
#define INC_2XD2_ENGINE_INPUTMANAGER_H
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "IInputHandler.h"
#include "2XD2/core/Vec2f.h"

namespace e2XD::framework::internal
{
    /**
     * Singleton class to manage input from keyboard, mouse, and other devices
     */
    class SFMLInputHandler final : public IInputHandler
    {
        sf::RenderWindow* window = nullptr;
        using keyboardMapType = std::unordered_map<Key, bool>;
        using mouseButtonMapType = std::unordered_map<MouseButton, bool>;
        keyboardMapType last_frame_keyboardState;
        keyboardMapType this_frame_keyboardState;
        mouseButtonMapType this_frame_mouseButtonState;
        mouseButtonMapType last_frame_mouseButtonState;

        std::tuple<bool, unsigned int, unsigned int> windowResized = {false, 0, 0};
        bool windowClosed = false;

        framework::Vec2f mousePosition;

        void handleEvent(const sf::Event& event);

        void handleKeyPress(sf::Keyboard::Key sfmlKeyCode);

        void handleKeyRelease(sf::Keyboard::Key sfmlKeyCode);

        void handleMouseButtonPress(sf::Mouse::Button sfmlButtonCode);

        void handleMouseButtonRelease(sf::Mouse::Button sfmlButtonCode);

    public:
        SFMLInputHandler() = default;

        ~SFMLInputHandler() override = default;

        void pollEvents() override;

        [[nodiscard]] bool isKeyReleased(Key keyCode) const override;
        [[nodiscard]] bool isMouseButtonPressed(MouseButton buttonCode) const override;
        [[nodiscard]] framework::Vec2f getMousePosition() const override;
        [[nodiscard]] bool isKeyPressed(Key keyCode) const override;
        [[nodiscard]] bool isMouseButtonReleased(MouseButton buttonCode) const override;

        [[nodiscard]] bool isKeyJustPressed(Key keyCode) const override;
        [[nodiscard]] bool isKeyJustReleased(Key keyCode) const override;
        [[nodiscard]] bool isMouseButtonJustPressed(MouseButton buttonCode) const override;
        [[nodiscard]] bool isMouseButtonJustReleased(MouseButton buttonCode) const override;

        /**
         *
         * @return (<isResized>, <newWindowWidth>, <newWindowHeight>)
         */
        std::tuple<bool, float, float> isWindowResized() const override;

        void initialize(sf::RenderWindow* window) override;
        [[nodiscard]] bool isWindowClosed() const override;
        void newFrame() override;
    };
} // core

#endif //INC_2XD2_ENGINE_INPUTMANAGER_H
