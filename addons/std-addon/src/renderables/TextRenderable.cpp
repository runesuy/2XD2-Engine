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
    }

    void TextRenderable::draw(const renderer::IRenderTarget& renderTarget) const
    {
        renderTarget.draw(_text);
    }

    void TextRenderable::setText(const std::string &text)
    {
        _text.setString(text);
    }

    void TextRenderable::setFontSize(const unsigned int size)
    {
        _text.setCharacterSize(size);
    }

    void TextRenderable::setFont(const FontType& font)
    {
        _text.setFont(font);
    }

    float TextRenderable::getWidth() const
    {
        return _text.getLocalBounds().width;
    }

    float TextRenderable::getHeight() const
    {
        return _text.getLocalBounds().height;
    }

    core::Vec2f TextRenderable::getSize() const
    {
        return {getWidth(), getHeight()};
    }

    core::Vec2f TextRenderable::getOrigin() const
    {
        return { _text.getOrigin().x, _text.getOrigin().y };
    }

    void TextRenderable::setOrigin(const core::Vec2f& origin)
    {
        _text.setOrigin(origin.x, origin.y);
    }
} // std_addon
// e2XD
