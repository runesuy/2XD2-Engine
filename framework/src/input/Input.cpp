//
// Created by rune-suy on 12/20/25.
//

#include "2XD2/framework/input/Input.h"


    namespace e2XD::framework
    {
        core::Vec2f Input::getMousePosition()
        {
            return _input_handler->getMousePosition();
        }

        bool Input::isKeyJustPressed(Key keyCode)
        {
            return _input_handler->isKeyJustPressed(keyCode);
        }

        bool Input::isKeyJustReleased(Key keyCode)
        {
            return _input_handler->isKeyJustReleased(keyCode);
        }

        bool Input::isKeyPressed(Key keyCode)
        {
            return _input_handler->isKeyPressed(keyCode);
        }

        bool Input::isKeyReleased(Key keyCode)
        {
            return _input_handler->isKeyReleased(keyCode);
        }

        bool Input::isMouseButtonJustReleased(MouseButton buttonCode)
        {
            return _input_handler->isMouseButtonJustReleased(buttonCode);
        }

        bool Input::isMouseButtonPressed(MouseButton buttonCode)
        {
            return _input_handler->isMouseButtonPressed(buttonCode);
        }

        bool Input::isMouseButtonReleased(MouseButton buttonCode)
        {
            return _input_handler->isMouseButtonReleased(buttonCode);
        }

        bool Input::isMouseButtonJustPressed(MouseButton buttonCode)
        {
            return _input_handler->isMouseButtonPressed(buttonCode);
        }

        bool Input::isWindowClosed()
        {
            return _input_handler->isWindowClosed();
        }

        std::tuple<bool, float, float> Input::isWindowResized()
        {
            return _input_handler->isWindowResized();
        }

        void Input::newFrame()
        {
            _input_handler->newFrame();
        }

        void Input::pollEvents()
        {
            _input_handler->pollEvents();
        }

        void Input::initialize(IInputHandler* inputHandler)
        {
            _input_handler = inputHandler;
        }


    } // framework
// e2XD