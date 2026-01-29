//
// Created by rune-suy on 1/29/26.
//

#include "2XD2/std_addon/nodes/ui/ColorRect.h"

#include "2XD2/framework/drawing/Renderer.h"


namespace e2XD::std_addon
{
    ColorRect::ColorRect()
    {
        _rectangleRenderable.setSize(getSize());
        _rectangleRenderable.setFillColor(_color);
    }

    void ColorRect::setColor(const Color& color)
    {
        _color = color;
    }

    const Color& ColorRect::getColor() const
    {
        return _color;
    }

    void ColorRect::_internal_onDraw()
    {
        const renderer::RenderCommand command = {
            renderLayer,
            &_rectangleRenderable,
            getGlobalPosition(),
            zIndex
        };
        Renderer::submit(command);
    }
} // std_addon
// e2XD
