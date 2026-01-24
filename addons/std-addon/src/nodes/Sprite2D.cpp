// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/17/25.
//

#include "../include/2XD2/std_addon/nodes/Sprite2D.h"
#include "2XD2/framework/drawing/Renderer.h"


namespace e2XD::std_addon
{
    void Sprite2D::_internal_onDraw()
    {
        const auto& position = getGlobalPosition();
        framework::Renderer::submit({
            renderLayer,
            &_renderable,
            {position.x, position.y},
            zIndex
        });

        Node2D::_internal_onDraw();
    }
} // framework
// e2XD
