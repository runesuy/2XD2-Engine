//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_INPUT_H
#define INC_2XD2_ENGINE_INPUT_H
#include "IInputHandler.h"
#include "2XD2/core/Vec2.h"


namespace e2XD::framework
    {
        class Input
        {
            inline static IInputHandler* _input_handler;

        public:

            static void initialize(IInputHandler* inputHandler);

            static void pollEvents();

            [[nodiscard]] static bool isKeyPressed(Key keyCode);

            [[nodiscard]] static bool isKeyJustPressed(Key keyCode);

            [[nodiscard]] static bool isKeyReleased(Key keyCode);

            [[nodiscard]] static bool isKeyJustReleased(Key keyCode);

            [[nodiscard]] static bool isMouseButtonPressed(MouseButton buttonCode);

            [[nodiscard]] static bool isMouseButtonJustPressed(MouseButton buttonCode);

            [[nodiscard]] static bool isMouseButtonReleased(MouseButton buttonCode);

            [[nodiscard]] static bool isMouseButtonJustReleased(MouseButton buttonCode);

            [[nodiscard]] static core::Vec2 getMousePosition();

            [[nodiscard]] static std::tuple<bool, float, float> isWindowResized();

            [[nodiscard]] static bool isWindowClosed();

            static void newFrame() ;
        };
    } // framework
// e2XD

#endif //INC_2XD2_ENGINE_INPUT_H