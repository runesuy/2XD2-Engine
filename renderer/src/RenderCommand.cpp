//
// Created by rune-suy on 12/19/25.
//

#include "2XD2/renderer/RenderCommand.h"


namespace e2XD::renderer
{
    RenderCommand::RenderCommand(const RenderLayer renderLayer, const sf::Drawable* drawable, const sf::Vector2f& position,
                                 const int zIndex) :
        renderLayer(renderLayer),
        drawable(drawable),
        position(position),
        zIndex(zIndex)
    {
    }
} // renderer
// e2XD
