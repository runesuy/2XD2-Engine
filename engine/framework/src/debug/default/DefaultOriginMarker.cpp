// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//


#ifndef e2XD_REMOVE_DEBUG
#include "2XD2/framework/debug/default/DefaultOriginMarker.h"

namespace e2XD::framework
{
    DefaultOriginMarker::DefaultOriginMarker()
    {
        _shape.setRadius(RADIUS);
        _shape.setOrigin(RADIUS, RADIUS);
        _shape.setFillColor(sf::Color::Red);
    }

    void DefaultOriginMarker::draw(renderer::IRenderTarget& renderTarget) const
    {
        renderTarget.draw(_shape);
    }
} // framework
#endif
// e2XD
