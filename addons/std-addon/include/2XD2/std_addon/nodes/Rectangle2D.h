// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_RECTANGLE2D_H
#define INC_2XD2_ENGINE_RECTANGLE2D_H

#include "2XD2/framework/nodes/Drawable2D.h"
#include "2XD2/std_addon/renderables/RectangleRenderable.h"

namespace e2XD::framework
{
    class DrawTarget;
}

namespace e2XD::std_addon
{
    /**
     * A 2D rectangle shape node.
     */
    class Rectangle2D : public framework::Drawable2D
    {
        RectangleRenderable _renderable;
    protected:

        void _internal_onDraw() override;
    public:
        /**
         * Get the rectangle renderable.
         * This is the renderable that handles the rectangle shape display.
         * @return A reference to the rectangle renderable.
         */
        RectangleRenderable& getRenderable() { return _renderable; }

        /**
         * Get the rectangle renderable.
         * This is the renderable that handles the rectangle shape display.
         * @return A const reference to the rectangle renderable.
         */
        const RectangleRenderable& getRenderable() const { return _renderable; }

    public:

    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_RECTANGLE2D_H
