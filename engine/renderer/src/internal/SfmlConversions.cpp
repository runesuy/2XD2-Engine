//
// Created by rune-suy on 1/19/26.
//

#include "2XD2/renderer/internal/SfmlConversions.h"

namespace e2XD::renderer::internal
{
    sf::Vector2f toSfmlVector(const core::Vec2f& vec)
    {
        return {vec.x, vec.y};
    }


} // e2XD::renderer::internal