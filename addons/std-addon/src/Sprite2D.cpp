//
// Created by rune-suy on 12/17/25.
//

#include "../include/2XD2/std_addon/Sprite2D.h"

#include "../../../engine/framework/include/2XD2/framework/resource_manager/SFMLTextureManager.h"
#include "2XD2/framework/resource_manager/Resources.h"
#include "2XD2/framework/resource_manager/Textures.h"
#include "../../../engine/framework/include/2XD2/framework/drawing/Renderer.h"


namespace e2XD::std_addon
{
    void Sprite2D::setTexture(const std::string& textureName)
    {
        setTexture(framework::Resources::Textures::getTexture(textureName));
    }

    void Sprite2D::setTexture(const sf::Texture& texture)
    {
        _sprite.setTexture(texture);
    }

    void Sprite2D::_internal_onDraw()
    {
        const auto& position = getGlobalPosition();
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
        framework::Renderer::submit({
            renderLayer,
            &_sprite,
            {position.x, position.y},
            zIndex
        });
    }
} // framework
// e2XD
