//
// Created by rune-suy on 1/10/26.
//

#include "2XD2/std_addon/Label.h"

#include "2XD2/renderer/Renderer.h"


namespace e2XD::std_addon
{
    void Label::setText(const std::string &text)
    {
        _text.setString(text);
    }

    void Label::setFontSize(const unsigned int size)
    {
        _text.setCharacterSize(size);
    }

    void Label::_internal_onDraw()
    {
        const auto renderer = renderer::Renderer::getInstance();
        const auto& position = getGlobalPosition();
        renderer->submit({
            renderLayer,
            &_text,
            {position.x, position.y},
            zIndex
        });
        Node2D::_internal_onDraw();
    }
} // std_addon
// e2XD
