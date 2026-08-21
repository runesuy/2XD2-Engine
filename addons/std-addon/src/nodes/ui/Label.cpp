// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/10/26.
//

#include "2XD2/std_addon/nodes/ui/Label.h"
#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/Game.h"

namespace e2XD::std_addon
{

    void Label::_internal_onDraw()
    {

        const auto& position = getGlobalPosition();
        framework::Renderer::submit({
            renderLayer,
            &_renderable,
            {position.x, position.y},
            zIndex
        });
        Drawable2D::_internal_onDraw();
    }

    const AlignVec& Label::getOriginAlign() const
    {
        return _originAlign;
    }

    void Label::recalculateOriginAlign()
    {
        const auto& [hAlign, vAlign] = _originAlign;

        float xOrigin = 0.0f;
        float yOrigin = 0.0f;

        switch (hAlign)
        {
        case HorizontalAlign::LEFT:
            xOrigin = 0.0f;
            break;
        case HorizontalAlign::CENTER:
            xOrigin = _renderable.getWidth() / 2.0f;
            break;
        case HorizontalAlign::RIGHT:
            xOrigin = _renderable.getWidth();
            break;
        }

        switch (vAlign)
        {
        case VerticalAlign::TOP:
            yOrigin = 0.0f;
            break;
        case VerticalAlign::CENTER:
            yOrigin = _renderable.getHeight() / 2.0f;
            break;
        case VerticalAlign::BOTTOM:
            yOrigin = _renderable.getHeight();
            break;
        }

        _renderable.setOrigin({xOrigin, yOrigin});
    }

    void Label::setOriginAlign(const AlignVec& originAlign)
    {
        _originAlign = originAlign;
        recalculateOriginAlign();
    }

    void Label::setText(const std::string& text)
    {
        _renderable.setText(text);
        recalculateOriginAlign();
    }

    void Label::setFontSize(const unsigned int size)
    {
        _renderable.setFontSize(size);
        recalculateOriginAlign();
    }

    void Label::setFont(const TextRenderable::FontType& font)
    {
        _renderable.setFont(font);
        recalculateOriginAlign();
    }
} // std_addon
// e2XD
