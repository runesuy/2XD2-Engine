//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERABLE_H
#define FLATLAND_RENDERABLE_H
#include "RenderLayer.h"


namespace e2XD::framework
{
    /**
     * An object renderable by the Renderer.
     */
    class Renderable
    {
    protected:
        RenderLayer renderLayer = RenderLayer::WORLD;

        int zIndex = 0;

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
    };
} // core
// e2XD

#endif //FLATLAND_RENDERABLE_H
