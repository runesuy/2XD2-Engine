//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_INPUT_H
#define INC_2XD2_ENGINE_INPUT_H
#include "IInputHandler.h"
#include "2XD2/core/Vec2f.h"


namespace e2XD::framework
{
    /**
     * Class providing static methods to manage input from keyboard, mouse, and other devices.
     *
     * Using the default game provided by framework, this class uses the inputhandler configured in the game config.
     */
    class Input
    {
        inline static IInputHandler* _input_handler;

    public:
        /**
         * Configure the input handler to use for input management
         * @param inputHandler ptr to the input handler to use. Object must outlive the usage of this class.
         */
        static void initialize(IInputHandler* inputHandler);

        /**
         * Poll all events from the window and update the input states.
         * Without calling this method, input states will not be updated.
         */
        static void pollEvents();

        /**
         * @param keyCode Key to check
         * @return true if the key was pressed or hold down in this frame
         */
        [[nodiscard]] static bool isKeyPressed(Key keyCode);

        /**
         *
         * @param keyCode Key to check
         * @return true if the key was just pressed in this frame, and was not pressed in the last frame
         */
        [[nodiscard]] static bool isKeyJustPressed(Key keyCode);

        /**
         *
         * @param keyCode Key to check
         * @return true if the key is not pressed or hold down in this frame
         */
        [[nodiscard]] static bool isKeyReleased(Key keyCode);

        /**
         *
         * @param keyCode
         * @return true if the key was just released in this frame, and was pressed in the last frame
         */
        [[nodiscard]] static bool isKeyJustReleased(Key keyCode);

        /**
         *
         * @param buttonCode
         * @return true if the mouse button is pressed or hold down in this frame
         */
        [[nodiscard]] static bool isMouseButtonPressed(MouseButton buttonCode);

        /**
         *
         * @param buttonCode
         * @return true if the mouse button was just pressed in this frame, and was not pressed in the last frame
         */
        [[nodiscard]] static bool isMouseButtonJustPressed(MouseButton buttonCode);

        /**
         *
         * @param buttonCode
         * @return true if the mouse button is not pressed or hold down in this frame
         */
        [[nodiscard]] static bool isMouseButtonReleased(MouseButton buttonCode);

        /**
         *
         * @param buttonCode
         * @return true if the mouse button was just released in this frame, and was pressed in the last frame
         */
        [[nodiscard]] static bool isMouseButtonJustReleased(MouseButton buttonCode);

        /**
         *
         * @return The current mouse position in window coordinates
         */
        [[nodiscard]] static framework::Vec2f getMousePosition();

        /**
         *
         * @return <resized, newSizeX, newSizeY> true if the window was resized in this frame, along with the new width and height
         */
        [[nodiscard]] static std::tuple<bool, float, float> isWindowResized();

        /**
         *
         * @return true if the window was closed in this frame
         */
        [[nodiscard]] static bool isWindowClosed();

        /**
         * called at the end of each frame to update internal states
         * does not replace pollEvents()
         */
        static void newFrame();
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_INPUT_H
