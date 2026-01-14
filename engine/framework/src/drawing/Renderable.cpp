// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/19/25.
//

#include "2XD2/framework/drawing/Renderable.h"


namespace e2XD::framework
{
    void Renderable::draw()
    {
        if (!visible) return;
        _internal_onDraw();
        onDraw();
    }

    void Renderable::setRenderLayer(RenderLayer renderLayer)
    {
        this->renderLayer = renderLayer;
    }

    void Renderable::setVisible(bool visible)
    {
        this->visible = visible;
    }
} // core
// e2XD