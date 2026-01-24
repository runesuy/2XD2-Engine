// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERABLE_H
#define FLATLAND_RENDERABLE_H
#include "2XD2/renderer/RenderLayer.h"


namespace e2XD::framework
{
    /**
     * An object renderable by the Renderer.
     */
    class Renderable
    {
    protected:
        int zIndex = 0;
        bool visible = true;
        RenderLayer renderLayer = RenderLayer::WORLD;

        /**
         * onDraw is a placeholder for user-defined draw logic.
         * This method is called during the draw phase of the renderable.
         */
        virtual void onDraw()
        {
        };

        /**
         * onDraw is a placeholder for internal draw logic.
         * This method is called during the draw phase of the renderable.
         */
        virtual void _internal_onDraw()
        {
        };

    public:
        virtual ~Renderable() = default;

        /**
         * Draw the renderable by calling internal and user-defined draw methods.
         */
        void draw();

        /**
         * Sets the visibility of the renderable.
         * If false the draw methods will not be called.
         * @param visible
         */
        virtual void setVisible(bool visible);

        /**
         * Set the render layer of the renderable.
         * @param renderLayer
         */
        virtual void setRenderLayer(RenderLayer renderLayer);
    };
} // core
// e2XD

#endif //FLATLAND_RENDERABLE_H
