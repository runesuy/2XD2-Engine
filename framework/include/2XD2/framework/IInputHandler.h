//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_IINPUTMANAGER_H
#define INC_2XD2_ENGINE_IINPUTMANAGER_H
#include "Key.h"
#include "MouseButton.h"

namespace e2XD {
    namespace framework {
        class IInputHandler {
        public:
            virtual ~IInputHandler() = default;

            virtual void pollEvents() = 0;

            virtual void isKeyPressed(Key keyCode) = 0;

            virtual void isKeyReleased(Key keyCode) = 0;

            virtual void isMouseButtonPressed(MouseButton buttonCode) = 0;

            virtual void getMousePosition(int &x, int &y) = 0;
        };
    } // framework
} // e2XD

#endif //INC_2XD2_ENGINE_IINPUTMANAGER_H