//
// Created by rune-suy on 1/19/26.
//

#ifndef FLATLAND_RECTANGLERENDERABLE_H
#define FLATLAND_RECTANGLERENDERABLE_H
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "2XD2/core/Vec2f.h"
#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    class RectangleRenderable : public renderer::IRenderable
    {
        sf::RectangleShape rectangleShape;
    public:
        void draw(renderer::IRenderTarget& renderTarget) const override;

        /**
         * Set the fill color of the rectangle.
         * @param color
         */
        void setFillColor(const sf::Color& color);

        /**
         * Set the size of the rectangle using game units.
         * @param size
         */
        void setSize(const core::Vec2f& size);

        float getHeight() const;

        float getWidth() const;
    };
} // std_addon
// e2XD

#endif //FLATLAND_RECTANGLERENDERABLE_H
