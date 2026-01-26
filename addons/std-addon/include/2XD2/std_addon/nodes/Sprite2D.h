// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/17/25.
//

#ifndef FLATLAND_SPRITE2D_H
#define FLATLAND_SPRITE2D_H
#include "2XD2/framework/nodes/Drawable2D.h"
#include "2XD2/std_addon/renderables/SpriteRenderable.h"


namespace e2XD::std_addon
{
    /**
     * A 2D sprite node.
     */
    class Sprite2D : public framework::Drawable2D
    {
        SpriteRenderable _renderable;

    public:
        Sprite2D() = default;
        ~Sprite2D() override = default;

        SpriteRenderable& getRenderable() { return _renderable; }

        const SpriteRenderable& getRenderable() const { return _renderable; }

    protected:
        void _internal_onDraw(const framework::DrawTarget& target) override;
    };
} // framework
// e2XD

#endif //FLATLAND_SPRITE2D_H
