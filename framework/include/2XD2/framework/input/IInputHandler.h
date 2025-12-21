//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_IINPUTMANAGER_H
#define INC_2XD2_ENGINE_IINPUTMANAGER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "../Key.h"
#include "../MouseButton.h"
#include "tuple"
#include "2XD2/core/Vec2f.h"


namespace e2XD::framework
{
    /**
     * InputHandler interface to manage input from keyboard, mouse, and other devices
     * Can be provided to the framework Game through IGameConfig.
     * When provided to the framework Game, it will be used by the static Input class to provide input states throughout the engine.
     */
    class IInputHandler
    {
    public:
        /**
         * Initialize the input handler with the given SFML RenderWindow.
         * The inputhandler will use this window to poll events and get input states.
         * @param window ptr to the active SFML RenderWindow
         */
        virtual void initialize(sf::RenderWindow* window) =0;

        virtual ~IInputHandler() = default;

        /**
         * Poll all events from the window and update the input states.
         * Without calling this method, input states will not be updated.
         */
        virtual void pollEvents() = 0;

        /**
         * @param keyCode Key to check
         * @return true if the key was pressed or hold down in this frame
         */
        [[nodiscard]] virtual bool isKeyPressed(Key keyCode) const = 0;

        /**
         *
         * @param keyCode Key to check
         * @return true if the key was just pressed in this frame, and was not pressed in the last frame
         */
        [[nodiscard]] virtual bool isKeyJustPressed(Key keyCode) const = 0;

        /**
         *
         * @param keyCode Key to check
         * @return true if the key is not pressed or hold down in this frame
         */
        [[nodiscard]] virtual bool isKeyReleased(Key keyCode) const = 0;

        /**
         *
         * @param keyCode
         * @return true if the key was just released in this frame, and was pressed in the last frame
         */
        [[nodiscard]] virtual bool isKeyJustReleased(Key keyCode) const = 0;

        /**
         *
         * @param buttonCode
         * @return true if the mouse button is pressed or hold down in this frame
         */
        [[nodiscard]] virtual bool isMouseButtonPressed(MouseButton buttonCode) const = 0;

        /**
         *
         * @param buttonCode
         * @return true if the mouse button was just pressed in this frame, and was not pressed in the last frame
         */
        [[nodiscard]] virtual bool isMouseButtonJustPressed(MouseButton buttonCode) const = 0;

        /**
         *
         * @param buttonCode
         * @return true if the mouse button is not pressed or hold down in this frame
         */
        [[nodiscard]] virtual bool isMouseButtonReleased(MouseButton buttonCode) const = 0;

        /**
         *
         * @param buttonCode
         * @return true if the mouse button was just released in this frame, and was pressed in the last frame
         */
        [[nodiscard]] virtual bool isMouseButtonJustReleased(MouseButton buttonCode) const = 0;

        /**
         *
         * @return The current mouse position in window coordinates
         */
        [[nodiscard]] virtual core::Vec2f getMousePosition() const = 0;

        /**
         *
         * @return <resized, newSizeX, newSizeY> true if the window was resized in this frame, along with the new width and height
         */
        [[nodiscard]] virtual std::tuple<bool, float, float> isWindowResized() const = 0;

        /**
         *
         * @return true if the window was closed in this frame
         */
        [[nodiscard]] virtual bool isWindowClosed() const = 0;

        /**
         * called at the end of each frame to update internal states
         * does not replace pollEvents()
         */
        virtual void newFrame() =0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_IINPUTMANAGER_H
