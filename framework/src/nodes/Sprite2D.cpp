//
// Created by rune-suy on 12/17/25.
//

#include "2XD2/framework/nodes/Sprite2D.h"

#include "../../include/2XD2/framework/resource_manager/SFMLTextureManager.h"
#include "2XD2/renderer/Renderer.h"


namespace e2XD::framework
{
    void Sprite2D::setTexture(const std::string& textureName)
    {
        setTexture(SFMLTextureManager::getInstance()->getTexture(textureName));
    }

    void Sprite2D::setTexture(const sf::Texture& texture)
    {
        _sprite.setTexture(texture);
    }

    void Sprite2D::_internal_onDraw()
    {
        auto* renderer = renderer::Renderer::getInstance();
        const auto& position = getGlobalPosition();
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
        renderer->submit({
            renderLayer,
            &_sprite,
            {position.x, position.y},
            zIndex
        });
    }
} // framework
// e2XD
