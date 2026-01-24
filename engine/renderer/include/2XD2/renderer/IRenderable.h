//
// Created by rune-suy on 1/19/26.
//
// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

#ifndef FLATLAND_RENDERER_RENDERABLE_H
#define FLATLAND_RENDERER_RENDERABLE_H
#include "IRenderTarget.h"


namespace e2XD::renderer
{
    /**
     * Interface for renderable objects.
     * Objects implementing this interface can be rendered by the Renderer.
     * Implement the onRender method to define custom rendering behavior.
     */
    class IRenderable
    {
    public:
        virtual ~IRenderable() = default;

        /**
         * Draw the object onto the given render target.
         * Executed by the Renderer on the exact moment of rendering the object.
         * @param renderTarget Render target to draw onto.
         */
        virtual void draw(IRenderTarget& renderTarget) const=0;
    };
} // renderer
// e2XD

#endif //FLATLAND_RENDERER_RENDERABLE_H
