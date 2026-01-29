// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/19/25.
//

#include "2XD2/framework/drawing/Drawable.h"


namespace e2XD::framework
{
    void Drawable::draw()
    {
        if (!visible) return;
        _internal_onDraw();
        _onDraw();
    }

    void Drawable::setRenderLayer(RenderLayer renderLayer)
    {
        this->renderLayer = renderLayer;
    }

    void Drawable::setVisible(bool visible)
    {
        this->visible = visible;

    }

    bool Drawable::isVisible() const
    {
        return visible;
    }
} // core
// e2XD