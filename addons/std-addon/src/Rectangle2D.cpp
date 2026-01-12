//
// Created by rune-suy on 12/20/25.
//

#include "2XD2/std_addon/Rectangle2D.h"

#include "2XD2/framework/drawing/Renderer.h"


namespace e2XD::std_addon
{
    void Rectangle2D::_internal_onDraw()
    {
        const auto& position = getGlobalPosition();
        rectangleShape.setOrigin(rectangleShape.getSize().x / 2, rectangleShape.getSize().y / 2);
        framework::Renderer::submit({
            renderLayer,
            &rectangleShape,
            {position.x, position.y},
            zIndex
        });
        Node2D::_internal_onDraw();
    }

    void Rectangle2D::setFillColor(const sf::Color& color)
    {
        rectangleShape.setFillColor(color);
    }

    void Rectangle2D::setSize(const core::Vec2f& size)
    {
        rectangleShape.setSize({size.x, size.y});
    }

    float Rectangle2D::getHeight() const
    {
        return rectangleShape.getSize().y;
    }

    float Rectangle2D::getWidth() const
    {
        return rectangleShape.getSize().x;
    }
} // framework
// e2XD
