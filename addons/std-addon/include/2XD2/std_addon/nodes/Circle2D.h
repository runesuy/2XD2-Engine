// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_CIRCLE2D_H
#define INC_2XD2_ENGINE_CIRCLE2D_H
#include "2XD2/framework/nodes/Node2D.h"
#include "2XD2/std_addon/renderables/CircleRenderable.h"


namespace e2XD::std_addon
{
    class Circle2D : public framework::Node2D
    {
    public:
        Circle2D() = default;
        ~Circle2D() override = default;

        CircleRenderable _renderable;

    protected:
        void _internal_onDraw() override;
    public:
        /**
         * Get the circle renderable.
         * This is the renderable that handles the circle shape display.
         * Can be used to change circle properties.
         * @return A reference to the circle renderable.
         */
        CircleRenderable& getRenderable() { return _renderable; }

        /**
         * Get the circle renderable.
         * This is the renderable that handles the circle shape display.
         * @return A const reference to the circle renderable.
         */
        const CircleRenderable& getRenderable() const { return _renderable; }
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_CIRCLE2D_H
