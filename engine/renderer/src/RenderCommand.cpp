// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/19/25.
//

#include "2XD2/renderer/RenderCommand.h"


namespace e2XD::renderer
{
    RenderCommand::RenderCommand(const RenderLayer renderLayer, const IRenderable* renderable,
                                 const core::Vec2f& position,
                                 const int zIndex) :
        renderLayer(renderLayer),
        renderable(renderable),
        position(position),
        zIndex(zIndex)
    {
    }
} // renderer
// e2XD
