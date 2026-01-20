// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERCOMMAND_H
#define FLATLAND_RENDERCOMMAND_H
#include "RenderLayer.h"
#include "2XD2/core/Vec2f.h"
#include "2XD2/renderer/IRenderable.h"

namespace e2XD::renderer
{
    /**
     * Command representing a renderable object with its render layer, position and z-index.
     * Can be given to the renderer to be drawn in the correct order.
     */
    struct RenderCommand
    {
        RenderLayer renderLayer;
        const IRenderable* renderable;
        core::Vec2f position;
        int zIndex;

        RenderCommand(RenderLayer renderLayer, const IRenderable* renderable, const core::Vec2f& position, int zIndex);

        RenderCommand(RenderCommand&&) noexcept = default;
        RenderCommand& operator=(RenderCommand&&) noexcept = default;

        RenderCommand(const RenderCommand&) = default;
        RenderCommand& operator=(const RenderCommand&) = default;
    };
} // renderer
// e2XD

#endif //FLATLAND_RENDERCOMMAND_H
