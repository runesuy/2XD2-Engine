//
// Created by rune-suy on 1/19/26.
//

#include "2XD2/std_addon/renderables/RectangleRenderable.h"


namespace e2XD::std_addon
{
    void RectangleRenderable::draw(renderer::IRenderTarget& renderTarget) const
    {
        renderTarget.draw(rectangleShape);
    }

    void RectangleRenderable::setFillColor(const sf::Color& color)
    {
        rectangleShape.setFillColor(color);
    }

    void RectangleRenderable::setSize(const core::Vec2f& size)
    {
        rectangleShape.setSize({size.x, size.y});
    }

    float RectangleRenderable::getHeight() const
    {
        return rectangleShape.getSize().y;
    }

    float RectangleRenderable::getWidth() const
    {
        return rectangleShape.getSize().x;
    }
} // std_addon
// e2XD
