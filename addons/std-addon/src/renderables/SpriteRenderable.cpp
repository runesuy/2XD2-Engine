//
// Created by rune-suy on 1/20/26.
//

#include "2XD2/std_addon/renderables/SpriteRenderable.h"

namespace e2XD::std_addon
{
    SpriteRenderable::SpriteRenderable()
    {
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    }

    void SpriteRenderable::draw(renderer::IRenderTarget& renderTarget) const
    {
        renderTarget.draw(_sprite);
    }

    void SpriteRenderable::setTexture(const sf::Texture& texture)
    {
        _sprite.setTexture(texture);
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    }
} // std_addon
// e2XD
