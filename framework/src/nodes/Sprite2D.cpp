//
// Created by rune-suy on 12/17/25.
//

#include "2XD2/framework/nodes/Sprite2D.h"

#include "2XD2/framework/SFMLTextureParser.h"
#include "2XD2/renderer/Renderer.h"


namespace e2XD::framework
{
    void Sprite2D::setTexture(const std::string& textureName)
    {
        setTexture(SFMLTextureParser::getInstance()->getTexture(textureName));
    }

    void Sprite2D::setTexture(const sf::Texture& texture)
    {
        _sprite.setTexture(texture);
    }

    void Sprite2D::_internal_onDraw()
    {
        const auto& position = getGlobalPosition();
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
        renderer::Renderer::getInstance()->draw(_sprite,{position.x, position.y});
    }
} // framework
// e2XD
