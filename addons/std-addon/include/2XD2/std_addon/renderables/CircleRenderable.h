//
// Created by rune-suy on 1/19/26.
//

#ifndef FLATLAND_CIRCLERENDERABLE_H
#define FLATLAND_CIRCLERENDERABLE_H
#include <SFML/Graphics/CircleShape.hpp>
#include "2XD2/renderer/IRenderable.h"


namespace e2XD::std_addon
{
    class CircleRenderable : public renderer::IRenderable
    {
        sf::CircleShape _shape;
    public:
        CircleRenderable();

        void draw(renderer::IRenderTarget& renderTarget) const override;

        void setRadius(float radius);

        [[nodiscard]] float getRadius() const;

        void setFillColor(const sf::Color& color);
    };
} // std_addon
// e2XD

#endif //FLATLAND_CIRCLERENDERABLE_H
