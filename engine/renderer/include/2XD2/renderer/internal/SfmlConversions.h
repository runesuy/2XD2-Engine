//
// Created by rune-suy on 1/19/26.
//
// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

#ifndef FLATLAND_SFMLCONVERSIONS_H
#define FLATLAND_SFMLCONVERSIONS_H
#include <SFML/System/Vector2.hpp>

#include "2XD2/core/Vec2f.h"

namespace e2XD::renderer::internal
{
    /**
     * Convert a core::Vec2f to an sf::Vector2f.
     * @param vec
     * @return
     */
    sf::Vector2f toSfmlVector(const core::Vec2f& vec);


} // e2XD::renderer::internal

#endif //FLATLAND_SFMLCONVERSIONS_H