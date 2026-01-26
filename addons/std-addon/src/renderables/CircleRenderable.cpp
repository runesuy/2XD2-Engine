//
// Created by rune-suy on 1/19/26.
//

#include "2XD2/std_addon/renderables/CircleRenderable.h"


namespace e2XD::std_addon
{
    CircleRenderable::CircleRenderable()
    {
        _shape.setOrigin(_shape.getRadius(), _shape.getRadius());
    }

    void CircleRenderable::draw(const renderer::IRenderTarget& renderTarget) const
    {
        renderTarget.draw(_shape);
    }

    float CircleRenderable::getRadius() const
    {
        return _shape.getRadius();
    }

    void CircleRenderable::setRadius(const float radius)
    {
        _shape.setRadius(radius);
        _shape.setOrigin(_shape.getRadius(), _shape.getRadius());
    }

    void CircleRenderable::setFillColor(const sf::Color& color)
    {
        _shape.setFillColor(color);
    }
} // std_addon
// e2XD
