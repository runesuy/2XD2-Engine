//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_RECTANGLE2D_H
#define INC_2XD2_ENGINE_RECTANGLE2D_H
#include <SFML/Graphics/RectangleShape.hpp>

#include "2XD2/core/Node2D.h"

namespace e2XD::std_addon
{
    /**
     * A 2D rectangle shape node.
     */
    class Rectangle2D : public core::Node2D
    {
        sf::RectangleShape rectangleShape;

    protected:
        void _internal_onDraw() override;

    public:
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
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_RECTANGLE2D_H
