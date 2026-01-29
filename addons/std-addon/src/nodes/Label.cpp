// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/10/26.
//

#include "../include/2XD2/std_addon/nodes/Label.h"

#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/Game.h"
#include "2XD2/framework/resource_manager/Fonts.h"
#include "2XD2/framework/resource_manager/Resources.h"


namespace e2XD::std_addon
{

    void Label::_internal_onDraw()
    {

        const auto& position = getGlobalPosition();
        framework::Renderer::submit({
            renderLayer,
            &_renderable,
            {position.x, position.y},
            zIndex
        });
        Drawable2D::_internal_onDraw();
    }
} // std_addon
// e2XD
