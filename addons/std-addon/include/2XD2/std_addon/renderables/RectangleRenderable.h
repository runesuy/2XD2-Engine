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
    /**
     * A rectangle shape renderable.
     */
    class RectangleRenderable : public renderer::IRenderable
    {
        sf::RectangleShape rectangleShape;

        using SizeType = float;
    public:
        RectangleRenderable();

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
        void setSize(const core::Vec2<SizeType>& size);

        /**
         * Set the width of the rectangle.
         * @param width
         */
        void setWidth(SizeType width);

        /**
         * Set the height of the rectangle.
         * @param height
         */
        void setHeight(SizeType height);

        /**
         * Get the height of the rectangle.
         * @return The height of the rectangle.
         */
        SizeType getHeight() const;

        /**
         * Get the width of the rectangle.
         * @return The width of the rectangle.
         */
        SizeType getWidth() const;
    };
} // std_addon
// e2XD

#endif //FLATLAND_RECTANGLERENDERABLE_H
