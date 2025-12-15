//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_INPUTMANAGER_H
#define INC_2XD2_ENGINE_INPUTMANAGER_H
#include <unordered_map>

#include "IInputHandler.h"
#include "2XD2/core/Vec2.h"

namespace e2XD::framework
{
    /**
     * Singleton class to manage input from keyboard, mouse, and other devices
     */
    class SFMLInputHandler : public IInputHandler
    {
        inline static SFMLInputHandler* _instance = nullptr;

        sf::RenderWindow* window = nullptr;

        std::unordered_map<Key, bool> keyboardPressedMap;
        std::unordered_map<Key, bool> keyboardReleasedMap;
        std::unordered_map<MouseButton, bool> mousePressedMap;
        std::unordered_map<MouseButton, bool> mouseReleasedMap;

        std::tuple<bool, unsigned int, unsigned int> windowResized = {false, 0, 0};
        bool windowClosed = false;

        core::Vec2 mousePosition;

        SFMLInputHandler() = default;

        void handleEvent(const sf::Event& event);

    public:
        SFMLInputHandler(const SFMLInputHandler&) = delete;

        ~SFMLInputHandler() override;

        SFMLInputHandler& operator=(const SFMLInputHandler&) = delete;

        static SFMLInputHandler* getInstance();

        void pollEvents() override;

        bool isKeyReleased(Key keyCode) const override;
        bool isMouseButtonPressed(MouseButton buttonCode) const override;
        core::Vec2 getMousePosition() const override;
        bool isKeyPressed(Key keyCode) const override;
        [[nodiscard]] bool isMouseButtonReleased(MouseButton buttonCode) const override;


        /**
         *
         * @return (<isResized>, <newWindowWidth>, <newWindowHeight>)
         */
        std::tuple<bool, float, float> isWindowResized() const override;

        void initialize(sf::RenderWindow* window);
        [[nodiscard]] bool isWindowClosed() const override;
    };
} // core

#endif //INC_2XD2_ENGINE_INPUTMANAGER_H
