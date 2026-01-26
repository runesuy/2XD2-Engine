// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/19/25.
//

#ifndef FLATLAND_RENDERABLE_H
#define FLATLAND_RENDERABLE_H
#include "DrawTarget.h"
#include "2XD2/renderer/RenderLayer.h"


namespace e2XD::framework
{
    /**
     * An object renderable by the Renderer.
     * @warning For most use-cases consider using Drawable2D instead.
     *
     * Does not inherit from Node to allow non-node renderables.
     *
     * Does not manage its own registration with the Renderer.
     * It is the responsibility of the user to register the renderable with the Renderer.
     */
    class Drawable
    {
        bool visible = true;
    protected:
        int zIndex = 0;
        RenderLayer renderLayer = RenderLayer::WORLD;

        /**
         * onDraw is a placeholder for user-defined draw logic.
         * This method is called during the draw phase of the renderable.
         */
        virtual void onDraw(const DrawTarget& target)
        {
        };

        /**
         * onDraw is a placeholder for internal draw logic.
         * This method is called during the draw phase of the renderable.
         */
        virtual void _internal_onDraw(const DrawTarget& target)
        {
        };

    public:
        virtual ~Drawable() = default;

        /**
         * Draw the renderable by calling internal and user-defined draw methods.
         */
        virtual void draw(const DrawTarget& target);

        /**
         * Sets the visibility of the renderable.
         * If false the draw methods will not be called.
         * @param visible
         */
        virtual void setVisible(bool visible);

        /**
         * Get the visibility of the renderable.
         * @return true if the renderable is visible, false otherwise.
         */
        [[nodiscard]] bool isVisible() const;

        /**
         * Set the render layer of the renderable.
         * @param renderLayer
         */
        virtual void setRenderLayer(RenderLayer renderLayer);
    };
} // core
// e2XD

#endif //FLATLAND_RENDERABLE_H
