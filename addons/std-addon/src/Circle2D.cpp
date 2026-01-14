// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/21/25.
//

#include "2XD2/std_addon/Circle2D.h"
#include "2XD2/framework/drawing/Renderer.h"


namespace e2XD::std_addon
{
    void Circle2D::_internal_onDraw()
    {
        const auto& position = getGlobalPosition();
        _shape.setOrigin(_shape.getRadius(), _shape.getRadius());
        framework::Renderer::submit({
            renderLayer,
            &_shape,
            {position.x, position.y},
            zIndex
        });
        Node2D::_internal_onDraw();
    }

    float Circle2D::getRadius() const
    {
        return _shape.getRadius();
    }

    void Circle2D::setRadius(float radius)
    {
        _shape.setRadius(radius);
    }

    void Circle2D::setFillColor(const sf::Color& color)
    {
        _shape.setFillColor(color);
    }
} // std_addon
// e2XD
