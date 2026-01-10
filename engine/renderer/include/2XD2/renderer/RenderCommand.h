//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERCOMMAND_H
#define FLATLAND_RENDERCOMMAND_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include "RenderLayer.h"


namespace e2XD::renderer
{
    /**
     * Command representing a renderable object with its render layer, position and z-index.
     * Can be given to the renderer to be drawn in the correct order.
     */
    struct RenderCommand
    {
        RenderLayer renderLayer;
        const sf::Drawable* drawable;
        sf::Vector2f position;
        int zIndex;

        RenderCommand(RenderLayer renderLayer, const sf::Drawable* drawable, const sf::Vector2f& position, int zIndex);

        RenderCommand(RenderCommand&&) noexcept = default;
        RenderCommand& operator=(RenderCommand&&) noexcept = default;

        RenderCommand(const RenderCommand&) = default;
        RenderCommand& operator=(const RenderCommand&) = default;
    };
} // renderer
// e2XD

#endif //FLATLAND_RENDERCOMMAND_H
