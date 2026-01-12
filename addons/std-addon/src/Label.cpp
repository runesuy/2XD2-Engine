//
// Created by rune-suy on 1/10/26.
//

#include "2XD2/std_addon/Label.h"

#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/Game.h"
#include "2XD2/framework/resource_manager/Fonts.h"
#include "2XD2/framework/resource_manager/Resources.h"


namespace e2XD::std_addon
{
    Label::Label()
    {
        _text.setFont(framework::Resources::Fonts::getFont(framework::Game::DEFAULT_FONT_NAME));
    }

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
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
        const auto& position = getGlobalPosition();
        framework::Renderer::submit({
            renderLayer,
            &_text,
            {position.x, position.y},
            zIndex
        });
        Node2D::_internal_onDraw();
    }
} // std_addon
// e2XD
