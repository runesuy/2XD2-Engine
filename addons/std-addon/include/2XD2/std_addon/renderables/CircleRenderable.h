//
// Created by rune-suy on 1/19/26.
//

#ifndef FLATLAND_CIRCLERENDERABLE_H
#define FLATLAND_CIRCLERENDERABLE_H
#include <SFML/Graphics/CircleShape.hpp>
#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    /**
     * Circle shape renderable.
     */
    class CircleRenderable : public renderer::IRenderable
    {
        sf::CircleShape _shape;
    public:
        CircleRenderable();

        void draw(renderer::IRenderTarget& renderTarget) const override;

        /**
         * Set the radius of the circle.
         * @param radius
         */
        void setRadius(float radius);

        /**
         *
         * @return The radius of the circle.
         */
        [[nodiscard]] float getRadius() const;

        /**
         * Set the fill color of the circle.
         * @param color
         */
        void setFillColor(const sf::Color& color);
    };
} // std_addon
// e2XD

#endif //FLATLAND_CIRCLERENDERABLE_H
