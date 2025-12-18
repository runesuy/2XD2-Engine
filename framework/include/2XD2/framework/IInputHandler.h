//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_IINPUTMANAGER_H
#define INC_2XD2_ENGINE_IINPUTMANAGER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "Key.h"
#include "MouseButton.h"
#include "tuple"
#include "2XD2/core/Vec2.h"


namespace e2XD::framework
{
    class IInputHandler
    {
    public:
        virtual ~IInputHandler() = default;

        virtual void pollEvents() = 0;

        [[nodiscard]] virtual bool isKeyPressed(Key keyCode) const = 0;

        [[nodiscard]] virtual bool isKeyJustPressed(Key keyCode) const = 0;

        [[nodiscard]] virtual bool isKeyReleased(Key keyCode) const = 0;

        [[nodiscard]] virtual bool isKeyJustReleased(Key keyCode) const = 0;

        [[nodiscard]] virtual bool isMouseButtonPressed(MouseButton buttonCode) const = 0;

        [[nodiscard]] virtual bool isMouseButtonJustPressed(MouseButton buttonCode) const = 0;

        [[nodiscard]] virtual bool isMouseButtonReleased(MouseButton buttonCode) const = 0;

        [[nodiscard]] virtual bool isMouseButtonJustReleased(MouseButton buttonCode) const = 0;

        [[nodiscard]] virtual core::Vec2 getMousePosition() const = 0;

        [[nodiscard]] virtual std::tuple<bool, float, float> isWindowResized() const = 0;

        [[nodiscard]] virtual bool isWindowClosed() const = 0;

        virtual void newFrame() =0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_IINPUTMANAGER_H