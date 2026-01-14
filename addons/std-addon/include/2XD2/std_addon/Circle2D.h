// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_CIRCLE2D_H
#define INC_2XD2_ENGINE_CIRCLE2D_H
#include <SFML/Graphics/CircleShape.hpp>

#include "2XD2/framework/nodes/Node2D.h"


namespace e2XD::std_addon
{
    class Circle2D : public framework::Node2D
    {
        sf::CircleShape _shape;
    public:
        Circle2D()=default;
        ~Circle2D()override=default;

        void setRadius(float radius);

        [[nodiscard]] float getRadius() const;

        void setFillColor(const sf::Color& color);

    protected:
        void _internal_onDraw() override;
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_CIRCLE2D_H
