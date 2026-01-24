//
// Created by rune-suy on 1/20/26.
//

#include "2XD2/std_addon/renderables/TextRenderable.h"

#include "2XD2/framework/Game.h"
#include "2XD2/framework/resource_manager/Fonts.h"
#include "2XD2/framework/resource_manager/Resources.h"


namespace e2XD::std_addon
{
    TextRenderable::TextRenderable()
    {
        _text.setFont(framework::Resources::Fonts::getFont(framework::Game::DEFAULT_FONT_NAME));
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    }

    void TextRenderable::draw(renderer::IRenderTarget& renderTarget) const
    {
        renderTarget.draw(_text);
    }

    void TextRenderable::setText(const std::string &text)
    {
        _text.setString(text);
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    }

    void TextRenderable::setFontSize(const unsigned int size)
    {
        _text.setCharacterSize(size);
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    }

    void TextRenderable::setFont(const FontType& font)
    {
        _text.setFont(font);
        _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    }
} // std_addon
// e2XD
