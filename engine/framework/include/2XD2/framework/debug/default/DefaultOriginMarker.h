// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/24/26.
//

#ifndef INC_2XD2_ENGINE_DEFAULTORIGINMARKER_H
#define INC_2XD2_ENGINE_DEFAULTORIGINMARKER_H
#ifndef e2XD_REMOVE_DEBUG
#include <SFML/Graphics/CircleShape.hpp>

#include "2XD2/renderer/IRenderable.h"


namespace e2XD::framework
{
    class DefaultOriginMarker : public renderer::IRenderable
    {
        static constexpr float RADIUS = 3.0f;
        sf::CircleShape _shape;

    public:
        DefaultOriginMarker();
        void draw(renderer::IRenderTarget& renderTarget) const override;
    };
} // framework
// e2XD

#endif

#endif //INC_2XD2_ENGINE_DEFAULTORIGINMARKER_H
