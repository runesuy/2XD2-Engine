//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_RECTANGLE2D_H
#define INC_2XD2_ENGINE_RECTANGLE2D_H
#include <SFML/Graphics/RectangleShape.hpp>

#include "2XD2/core/Node2D.h"

namespace e2XD::framework
{
    class Rectangle2D : public core::Node2D
    {
        sf::RectangleShape rectangleShape;
    protected:
        void _internal_onDraw() override;

    public:
        void setFillColor(const sf::Color& color);

        void setSize(const core::Vec2& size);
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_RECTANGLE2D_H
